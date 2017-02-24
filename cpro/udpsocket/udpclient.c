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

#define BUF_SIZE        256
#define PORT            5656

struct net_msg
{
    int cmd;
    char buf[BUF_SIZE];
};

int main(int argc, char **argv)
{
    int csocket;
    int ret, len, flag = 1;
    struct sockaddr_in cin;
    struct net_msg msg;
    msg.cmd = 0;
    
    csocket = socket(PF_INET, SOCK_DGRAM, 0);
    if(csocket < 0)
    {
        fprintf(stderr, "csocket fail\n");
        return -1;
    }
    
    setsockopt(csocket, SOL_SOCKET, SO_BROADCAST, &flag, sizeof(int));
    
    cin.sin_family = AF_INET;
    cin.sin_port = htons(PORT);
    cin.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    bzero(cin.sin_zero, 8);
    
    memset(msg.buf, 0, sizeof(msg.buf));
    strcpy(msg.buf, "this is a test");
    sendto(csocket, (void *)&msg, sizeof(msg), 0, (struct sockaddr *)&cin, 
            sizeof(cin));
            
    sleep(1);
    close(csocket);
    return 0;    
}
