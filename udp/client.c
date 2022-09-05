#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 6000

int main()
{

    int sockfd, n;
    char buffer[255];
    struct sockaddr_in servAddr, cliaddr;
    socklen_t clilen;

    if (sockfd = socket(AF_INET, SOCK_DGRAM, 0) < 0)
    {
        printf("ERROR IN SOCKET \n");
        return -1;
    }
    else
        printf("SOCKET SUCCESS \n");

    memset(&servAddr, 0, sizeof(servAddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("ENTER MSG:\n");
    bzero(buffer, 255);
    fgets(buffer, 255, stdin);

    // write(sockfd, buffer, 255);

    n = sendto(sockfd, buffer, 255, MSG_WAITALL, (struct sockaddr *)&servAddr, sizeof(servAddr));
    if (n<0)
    {
        printf("SEND FAILED\n");
    }

    return 0;
}