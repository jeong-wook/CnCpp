#include "unp.h"

//winsock2 를 사용하기 위한 wrarpper 함수
//윈도우 환경에서 소켓을 사용하려면 이 함수를  맨 처음에 실행을 해야 한다.
//소켓 통신이 완전히 끝나면 WSACleanup()로 끝내야 한다.
void STARTUP(){
    #ifdef WIN32
    WSADATA wsaData;
    int err;
    if ( (err = WSAStartup(MAKEWORD(2,2),&wsaData)) != 0 ){
        printf("winsock startup error(%d)\n",err);
        exit(-1);
    }
    #endif
}

//에러가 발생시 에러메시지를 내고 강제 종료.
void error_sys(const char * message){
    
    #ifdef WIN32
    WSACleanup();
    printf("%s(%d)\n",message,WSAGetLastError());
    #else
    printf("%s(%d)\n",message,errno);
    #endif
    exit(-1);
}
