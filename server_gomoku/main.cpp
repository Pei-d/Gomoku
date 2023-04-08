#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock2.h>
#include<windows.h>
#include<process.h>
#define BUF_SIZE 1024
#define MSG_SIZE 512
using namespace std;

enum MsgType{DROP=0, USERNAME,CHESSTYPE,GIVEUP,GOBACK,PEACE,MESSAGE,LOSS,WIN,TIE,AGREE,REJECT,INVALID,START,OK,QUIT};
enum ChessType{BLANK=0,BLACK,WHITE};
typedef struct{
    int x,y;
    ChessType chessType;
}location;
typedef struct {
    union{
        location loc;
        char message[MSG_SIZE] = {'\0'};
    }u;
    MsgType type;
}Data;

void ErrorHandling(char *);
void mainFun(SOCKET scok, char * msg, int len);
unsigned WINAPI threadFun(void* arg);
void toAll(Data*);
void giveup(SOCKET, Data*);
void toOther(SOCKET, Data*);
void toSelf(SOCKET, Data*);

SOCKET clntSocks[2];
char* name[2];
int clntCnt=0;
HANDLE hMutex;
MsgType msgType=CHESSTYPE;
int x=-1,y=-1;


int main(int argc,char* argv[]) {
    WSAData wsaData;
    SOCKET servSock, clntSock;
    Data* data = (Data*)malloc(sizeof(Data));

    SOCKADDR_IN servAdr, clntAdr;
    int clntAdrSize;
    HANDLE hThread;
    if (argc!=2){
        printf("Usage : %s <port>\n", argv[0]);
    }
    if(WSAStartup(MAKEWORD(2,2), &wsaData)!= 0){
        ErrorHandling("WSAStartup() error!");
    }
    servSock = socket(PF_INET, SOCK_STREAM, 0);
    if(servSock==INVALID_SOCKET){
        ErrorHandling("socket() error!");
    }
    memset(&servAdr, 0, sizeof(servAdr));
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr=htonl(INADDR_ANY);
    servAdr.sin_port= htons(atoi(argv[1]));
    if(bind(servSock, (SOCKADDR*)&servAdr,sizeof(servAdr))==SOCKET_ERROR){
        ErrorHandling("bind() error");
    }
    if(listen(servSock, 1)==SOCKET_ERROR)
        ErrorHandling("listen() error!");
    hMutex = CreateMutex(NULL, FALSE, NULL);
    while(1){
        clntAdrSize = sizeof(clntAdr);
        clntSock = accept(servSock, (SOCKADDR*)&clntAdr, &clntAdrSize);
        if(clntSock==-1) {
            ErrorHandling("accept() error!");
            break;
        }
        recv(clntSock, (char*)data, sizeof(Data), 0);
        if(data->type!=USERNAME){
            printf("连接错误！");
            break;
        }
        WaitForSingleObject(hMutex, INFINITE);
        clntSocks[clntCnt] = clntSock;
        name[clntCnt] = (char*)malloc(MSG_SIZE);
        strcpy(name[clntCnt++], data->u.message);
        if(clntCnt==2){
            send(clntSocks[0], (char*)data, sizeof(Data),0);
            strcpy(data->u.message, name[0]);
            send(clntSock, (char*)data,sizeof(Data), 0);
            data->type=OK;
            send(clntSocks[0], (char*)data, sizeof(Data),0);
            send(clntSock, (char*)data,sizeof(Data), 0);
        }
        ReleaseMutex(hMutex);
        hThread = (HANDLE)_beginthreadex(NULL, 0, threadFun, (void*)&clntSock, 0, NULL);
        printf("connected clinet %d!\n", clntCnt);
    }
    closesocket(servSock);
    WSACleanup();
    return 0;
}

unsigned WINAPI threadFun(void* arg){
    SOCKET clntSock = *((SOCKET*)arg);
    Data* data = (Data*) malloc(sizeof(Data));
    while((recv(clntSock, (char*)data, sizeof(Data), 0))>0){
//        toAll(data);
        switch(data->type){
            case DROP: {
                x = data->u.loc.x;
                y = data->u.loc.y;
                toAll(data);
                break;
            }
            case START:{
                WaitForSingleObject(hMutex,INFINITE);
                msgType = START;
                ReleaseMutex(hMutex);
                toOther(clntSock, data);
                break;
            }
            case MESSAGE:
                toAll(data);
                break;
            case GIVEUP:
                giveup(clntSock,data);
                break;
            case PEACE:
                WaitForSingleObject(hMutex,INFINITE);
                msgType = PEACE;
                ReleaseMutex(hMutex);
                toOther(clntSock, data);
                break;
            case GOBACK:{
                if(x==-1||y==-1){
                    data->type = INVALID;
                    toSelf(clntSock, data);
                }else{
                    WaitForSingleObject(hMutex,INFINITE);
                    msgType = GOBACK;
                    ReleaseMutex(hMutex);
                    toOther(clntSock, data);
                }
                break;
            }
            case REJECT:
                toOther(clntSock,data);
                break;
            case AGREE: {
                WaitForSingleObject(hMutex, INFINITE);
                switch (msgType) {
                    case START: {
                        toOther(clntSock, data);
                        data->type = CHESSTYPE;
                        data->u.loc.chessType = WHITE;
                        toSelf(clntSock, data);
                        data->u.loc.chessType = BLACK;
                        toOther(clntSock, data);
                        WaitForSingleObject(hMutex,INFINITE);
                        x = -1;
                        y = -1;
                        break;
                    }
                    case GOBACK:{
                        toOther(clntSock, data);
                        data->type = DROP;
                        data->u.loc.x = x;
                        data->u.loc.y = y;
                        data->u.loc.chessType = BLANK;
                        x = -1;
                        y = -1;
                        toAll(data);
                        break;
                    }
                    case PEACE:{
                        data->type = TIE;
                        toAll(data);
                        break;
                    }
                };
                ReleaseMutex(hMutex);
                break;
            }
            default:
                ErrorHandling("Unknow message type!\n");
        }
    }
    data->type=QUIT;
    toOther(clntSock,data);
    WaitForSingleObject(hMutex, INFINITE);
    for(int i=0;i<clntCnt;i++){
        if(clntSock == clntSocks[i]){
            while(i<clntCnt-1){
                clntSocks[i] = clntSocks[i+1];
                char* temp = name[i];
                name[i] = name[i+1];
                free(temp);
                name[i+1] = nullptr;
                i++;
            }
            break;
        }
    }
    clntCnt--;
    printf("connects %d\n",clntCnt);
    ReleaseMutex(hMutex);
    closesocket(clntSock);
    return 0;
}

void toSelf(SOCKET clntSock,Data * data){
    send(clntSock, (char*)data, sizeof(Data), 0);
}


void toOther(SOCKET clntSock, Data * data) {
    WaitForSingleObject(hMutex, INFINITE);
    for(int i=0;i<clntCnt;++i){
        if(clntSock!=clntSocks[i]){
            send(clntSocks[i],(char*)data,sizeof(Data),0);
        }
    }
    ReleaseMutex(hMutex);
}

void toAll(Data* data){
    WaitForSingleObject(hMutex, INFINITE);
    for(int i=0;i<clntCnt;i++){
        send(clntSocks[i], (char *)data, sizeof(Data), 0);
    }
    ReleaseMutex(hMutex);
}

void giveup(SOCKET clntSock, Data * data) {
    WaitForSingleObject(hMutex, INFINITE);
    for(int i=0;i<clntCnt;++i){
        if(clntSock==clntSocks[i]){
            data->type = LOSS;
        }else{
            data->type = WIN;
        }
        send(clntSocks[i], (char*)data,sizeof(Data),0);
    }
    ReleaseMutex(hMutex);
}

void ErrorHandling(char *message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
