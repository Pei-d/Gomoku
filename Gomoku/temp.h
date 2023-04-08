//
// Created by 裴栋 on 2023/4/4.
//

#ifndef GOMOKU_TEMP_H
#define GOMOKU_TEMP_H
#define BUF_SIZE 1024
#define MSG_SIZE 512
enum ChessType{BLANK=0, BLACK, WHITE};
enum State{READY,RUNING};
enum MsgType{DROP=0, USERNAME,CHESSTYPE,GIVEUP,GOBACK,PEACE,MESSAGE,LOSS,WIN,TIE,AGREE,REJECT,INVALID,START,OK,QUIT};
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

#endif //GOMOKU_TEMP_H
