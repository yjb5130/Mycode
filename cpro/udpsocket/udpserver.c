//******************************************************************************
//yjb5130 Software
//******************************************************************************

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE    256
#define PORT        5656

struct net_msg
{
    int cmd;
    char buf[BUF_SIZE];
};

int main(int argc, char **argv)
{
    int csocket;
    int ret, flag = 1, len;
    struct sockaddr_in sin, cin;
    struct net_msg msg;
    msg.cmd = 1;
    
    csocket = socket(PF_INET, SOCK_DGRAM, 0);
    if(csocket < 0)
    {
        fprintf(stderr, "csocket fail\n");
        return -1;
    }
    
    setsockopt(csocket, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int));
    
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(sin.sin_zero, 8);
    
    ret = bind(csocket, (struct sockaddr *)&sin, sizeof(sin));    
    if(ret < 0)
    {
        close(csocket);
        fprintf(stderr, "bind error\n");
        return -1;
    }
    
    cin.sin_family = AF_INET;
    len = sizeof(cin);
    while(1)
    {
        recvfrom(csocket, (void *)&msg, sizeof(msg), 0, 
                    (struct sockaddr *)&cin, &len);
        printf("cmd: %d\t %s\n", msg.cmd, msg.buf);
    }
    
    close(csocket);
    
    return 0;
}
