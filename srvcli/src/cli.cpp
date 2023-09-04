#include "unp.h"

int main(int argc , char ** argv){
    int sockfd , n;
    char recv_buf[1024];
    struct sockaddr_in serveraddr;
    STARTUP();

    if((sockfd = socket(AF_INET, SOCK_STREAM,0)) < 0 ){
        error_sys("socket error");
    }
    
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(13000);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("client start\n");
    if( connect(sockfd,(const sockaddr *)&serveraddr,sizeof(serveraddr)) < 0 ){
        closesocket(sockfd);
        error_sys("connect error");
    }

    while( (n=recv(sockfd, recv_buf, 1024,0)) > 0 ){
        printf("%s\n",recv_buf);
    }
    closesocket(sockfd);
    CLEANUP();
    printf("client end\n");
    return 0;
}