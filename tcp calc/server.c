#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define port 6000

int calc(int choice, int n1, int n2){

    int sum, minus, mul;
    switch (choice)
    {
    case 1:
        sum = n1 + n2;
        return sum;
        break;

    case 2:
        mul = n1 * n2;
        return mul;

    case 3:
            minus = n1 - n2;
            return minus;

        default:
        break;
    }
}

int main()
{
    int sockfd, newsockfd, n;
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
        printf("socket creation completed");
    }

    bzero((char *)&servAddr, sizeof(servAddr));
    bzero((char *)&cliaddr, sizeof(cliaddr));

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        printf("bind unsuccessful");
    }
    else
    {
        printf("bind successfull");
    }
    listen(sockfd, 5);
    clilen = sizeof(cliaddr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
    if (newsockfd < 0)
    {
        printf("error in accept \n");
        return -1;
    }
    else
        printf("connection accepted\n");

    int choice, n1, n2;

    read(newsockfd, &choice, 255);

    read(newsockfd, &n1, sizeof(int));
    read(newsockfd, &n2, sizeof(int));

    int ans = calc(choice, n1, n2);

    write(newsockfd, (char *)ans, sizeof(char));
}