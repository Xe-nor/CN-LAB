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
    char buffer[MAXLINE];
    int x, y, z, x1, y1, n, a, z1, z2, z3;
    char *hello = "Hello from server";
    char *op = "choose operation to do 1.Addition 2.Subtraction 3.Multiplication 4.Division";
    struct sockaddr_in servaddr, cliaddr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    int clientsize = sizeof(cliaddr);
    listen(sockfd, 5);

    x1 = recvfrom(sockfd, &x, sizeof(int), MSG_WAITALL, (struct sockaddr *)&cliaddr,
                  &clientsize);
    y1 = recvfrom(sockfd, &y, sizeof(int), MSG_WAITALL, (struct sockaddr *)&cliaddr,
                  &clientsize);
    printf("Two nos received\n");
    sendto(sockfd, (const char *)op, strclientsize(op),
           MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
           clientsize);
    z = x + y;
    z1 = x - y;
    z2 = x * y;
    z3 = x / y;
    int num;

    // ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags, struct sockaddr *src_addr, socklen_t *addrlen);

    num = recvfrom(sockfd, &a, sizeof(int), MSG_WAITALL, (struct sockaddr *)&cliaddr,
                   &clientsize);
    switch (a)
    {
    case 1:
        printf("Addition\n");
        sendto(sockfd, &z, sizeof(int), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, clientsize);
        break;
    case 2:
        printf("Subtraction\n");
        sendto(sockfd, &z1, sizeof(int), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, clientsize);
        break;
    case 3:
        printf("Multiplication\n");
        sendto(sockfd, &z2, sizeof(int), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, clientsize);
        break;
    case 4:
        printf("Division\n");
        sendto(sockfd, &z3, sizeof(int), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, clientsize);
        break;
    default:
        printf("invalid option");
        break;
    }
    return 0;
}