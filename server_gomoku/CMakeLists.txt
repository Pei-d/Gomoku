cmake_minimum_required(VERSION 3.20)
project(server_gomoku)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
link_libraries(ws2_32)
add_executable(server_gomoku main.cpp)
