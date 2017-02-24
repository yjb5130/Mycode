//******************************************************************************
//yjb5130 Software
//******************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>

/* network flags */
#define PORT        5656
#define NET_SIZE    256

/* network command */
#define NET_MESSAGE         1
#define NET_FILE            2

/* transmit struct */
struct net_msg 
{
    int cmd;
    int sockfd;
    char buf[NET_SIZE];
};

void recvdata(void *args)
{
    int ret;
    int csocket = *((int *)args);
    struct net_msg recv_msg;
    while(1)
    {
        ret = recv(csocket, (void *)&recv_msg, sizeof(recv_msg), 0);
        if(ret <= 0 || strncmp(recv_msg.buf, "quit", 4) == 0)
        {
            fprintf(stderr, "client quit or recv error\n");
            break;
        }
        printf("recv: %s", recv_msg.buf);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    int ssocket, csocket;
    int flag = 1, len, ret;
    pthread_t pid;
    struct sockaddr_in sin, cin;
    struct net_msg send_msg;
    
    ssocket = socket(PF_INET, SOCK_STREAM, 0);
    if(ssocket < 0)
    {
        printf("ssocket fail\n");
        return -1;
    }
    
    setsockopt(ssocket, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int));
    
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(sin.sin_zero, 8);
    
    ret = bind(ssocket, (struct sockaddr *)&sin, sizeof(sin));
    if(ret < 0)
    {
        close(ssocket);
        printf("bind error\n");
        return -1;
    }
    
    ret = listen(ssocket, 3);
    if(ret < 0)
    {
        close(ssocket);
        printf("listen error\n");
        return -1;
    }
    
    cin.sin_family = AF_INET;
    len = sizeof(cin);
    csocket = accept(ssocket, (struct sockaddr *)&cin, &len);
    if(csocket < 0)
    {
        close(ssocket);
        printf("csocket fail\n");
    }
    else
    {
        printf("accept a client\n");
    }
    
    ret = pthread_create(&pid, NULL, (void *)recvdata, (void *)&csocket);    
    
    send_msg.sockfd = csocket;
    send_msg.cmd = NET_MESSAGE;
    while(1)
    {
        memset(send_msg.buf, 0, sizeof(send_msg.buf));
        fgets(send_msg.buf, sizeof(send_msg.buf), stdin);
        if(strncmp(send_msg.buf, "quit", 4) == 0)
        {
            printf("server quit\n");
            break;
        }
        else if(strcmp(send_msg.buf, "\n") == 0)
        {
            continue;
        }
        send(csocket, (void *)&send_msg, sizeof(send_msg), 0);
    }
    
    close(ssocket);
    close(csocket);

    return 0;
}
