#ifndef __UNP_H_
#define __UNP_H_

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#ifdef WIN32
#include <winsock2.h>
#else
#include<unistd.h>
#include<arpa/inet.h>
#include <sys/socket.h>
#includ <errno.h>
extern errno;
#endif



#ifdef WIN32
#define CLEANUP() WSACleanup()
#else
#define CLEANUP()
#endif

extern void STARTUP();
extern void error_sys(const char * message);

#endif //__UNP_H_
