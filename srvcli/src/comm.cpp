#include "unp.h"

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
