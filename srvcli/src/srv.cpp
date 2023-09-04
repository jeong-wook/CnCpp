#include "unp.h"

int main(int argc , char ** argv){
    int connfd , listenfd , cli_len;
    char buf[1024];
    struct sockaddr_in serveraddr, clientaddr;
    STARTUP();

    if((listenfd = socket(AF_INET, SOCK_STREAM,0)) < 0 ){
        error_sys("socket error");
    }
    
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(13000);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    printf("server start");

    if( bind(listenfd,(const sockaddr *)&serveraddr, sizeof(serveraddr)) < 0 ){
        closesocket(listenfd);
        error_sys("bind error");
    }

    if ( listen(listenfd, 1024) < 0 ){
        closesocket(listenfd);
        error_sys("listen error");
    }

    while(1){
        memset(&clientaddr,0,sizeof(clientaddr));
        
        connfd = accept(listenfd, (sockaddr *)&clientaddr , &cli_len );
        if (connfd < 0){
            closesocket(listenfd);
            error_sys("accept error");
        }
        time_t t = time(NULL);
        sprintf(buf,"%s",ctime(&t));
        send(connfd,buf,strlen(buf),0);
        closesocket(connfd);

    }
    closesocket(listenfd);
    CLEANUP();
    return 0;
}