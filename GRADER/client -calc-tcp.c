#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 6000

int main(){

    int sockfd, newsockfd, n;
    char buffer[255];
    struct sockaddr_in servAddr, cliaddr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }
    else
    {
        printf("socket creation completed\n");
    }

    bzero((char *)&servAddr, sizeof(servAddr));

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd,(struct sockaddr *)&servAddr , sizeof(servAddr))<0)
    {
        printf("error in connect");
    }

    int num1, num2, num3;

    bzero(buffer, 255);
    read(sockfd, buffer, 255);
    printf("%s", buffer);
    scanf("%d", &num1);
    write(sockfd, &num1, sizeof(num1));

    bzero(buffer, 255);
    read(sockfd, buffer, 255);
    printf("%s", buffer);
    scanf("%d", &num2);
    write(sockfd, &num2, sizeof(num2));

    bzero(buffer, 255);
    read(sockfd, buffer, 255);
    printf("%s", buffer);
    scanf("%d", &num3);
    write(sockfd, &num3, sizeof(num3));

    bzero(buffer, 255);
    read(sockfd, buffer, 255);
    printf("%s\n", buffer);

    bzero(buffer, 255);
    read(sockfd, buffer, 255);
    printf(" %s\n", buffer);

    bzero(buffer, 255);
    read(sockfd, buffer, 255);
    printf(" %s\n", buffer);
    // bzero(buffer, 255);
    // read(sockfd, buffer, 255);
    // printf("%s\n", buffer);

    return 0;
}