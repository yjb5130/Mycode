//******************************************************************************
//yjb5130 Software
//******************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>

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
        if(ret <= 0)
        {
            fprintf(stderr, "server quit or recv error\n");
            break;
        }
        printf("recv: %s", recv_msg.buf);
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    int csocket;
    int ret, len, flag = 1;
    pthread_t pid;
    struct sockaddr_in cin;
    struct hostent *host;
    struct net_msg send_msg;
    
    csocket = socket(PF_INET, SOCK_STREAM, 0);
    if(csocket < 0)
    {
        printf("csocket fail\n");
        return -1;
    }
    
    host = gethostbyname("127.0.0.1");
    
    cin.sin_family = AF_INET;
    cin.sin_port = htons(PORT);
    cin.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(cin.sin_zero, 8);
    ret = connect(csocket, (struct sockaddr *)&cin, sizeof(cin));
    if(ret < 0)
    {
        close(csocket);
        printf("connect error\n");
        return -1;
    }
    else
    {
        printf("connect to server succeed\n");
    }
    
    ret = pthread_create(&pid, NULL, (void *)recvdata, (void *)&csocket);
    if(ret < 0)
    {
        printf("crate pthread fail\n");
        close(csocket);
        return -1;
    }
    
    send_msg.sockfd = csocket;
    send_msg.cmd = NET_MESSAGE;
    while(1)
    {
        memset(send_msg.buf, 0, sizeof(send_msg.buf));
        fgets(send_msg.buf, sizeof(send_msg.buf), stdin);
        if(strncmp(send_msg.buf, "quit", 4) == 0)
        {
            fprintf(stderr, "quit\n");
            break;
        }
        else if(strcmp(send_msg.buf, "\n") == 0)
        {
            continue;
        }
        ret = send(csocket, (void *)&send_msg, sizeof(send_msg), 0);
    }
    
    close(csocket);
    
    return 0;
}
