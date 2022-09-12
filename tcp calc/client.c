#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 6000

int main()
{

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
        printf("socket creation completed\n\n");
    }

    bzero((char *)&servAddr, sizeof(servAddr));

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        printf("error in connect");
    }

    int num1, num2, num3 ,ans;

    printf("ENTER YOUR CHOICE :\n 1.add \n 2.mul \n 3.sub\n");
    scanf("%d", &num1);

    printf("enter num 1\n");
    scanf("%d", &num2);
    write(newsockfd, &num2, sizeof(int));

    printf("enter num 2\n");
    scanf("%d", &num3);
    write(newsockfd, &num3, sizeof(int));

    read(newsockfd,&ans, sizeof(int));
    printf("ans is %d", ans);
}