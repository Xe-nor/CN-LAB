#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

// Driver code
int main()
{
    int sockfd;
    int buff;
    int n, n1, n2, opertaion, a;
    char buffer[MAXLINE];
    char *hello = "Hello from client";
    struct sockaddr_in servaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    int len = sizeof(servaddr);

    printf("Enter the first no\n");
    scanf("%d", &n1);
    printf("Enter the 2nd no\n");
    scanf("%d", &n2);
    sendto(sockfd, &n1, sizeof(int), MSG_WAITALL, (struct sockaddr *)&servaddr, len);
    sendto(sockfd, &n2, sizeof(int), MSG_WAITALL, (struct sockaddr *)&servaddr, len);
    printf("Tow nos sent to sever\n");
    int y = recvfrom(sockfd, (char *)buffer, MAXLINE,
                     MSG_WAITALL, (struct sockaddr *)&servaddr,
                     &len);
    buffer[n] = '\0';
    printf("%s\n", buffer);
    printf("Enter client choice :");
    scanf("%d", &a);
    sendto(sockfd, &a, sizeof(int), MSG_WAITALL, (struct sockaddr *)&servaddr, len);

    n = recvfrom(sockfd, &buff, sizeof(int),
                 MSG_WAITALL, (struct sockaddr *)&servaddr,
                 &len);

    switch (a)
    {
    case 1:
        printf("result after addition is %d\n", buff);
        break;
    case 2:
        printf(" result after subtraction is%d\n", buff);
        break;
    case 3:
        printf("result after multiplication is%d\n", buff);
        break;
    case 4:
        printf("result after division is %d\n", buff);
        break;
    default:

        break;
    }
    close(sockfd);
    return 0;
}