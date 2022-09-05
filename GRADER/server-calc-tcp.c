#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 6000

char grader(int grade)
{
    switch (grade)
    {
    case 91 ... 100:
        return 'O';
        break;
    case 81 ... 90:
        return 'E';
        break;
    case 71 ... 80:
        return 'A';
        break;
    case 61 ... 70:
        return 'B';
        break;
    case 51 ... 60:
        return 'C';
        break;
    case 0 ... 50:
        return 'F';
        break;

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

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
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

    int grade1, grade2, grade3;

    if (n = write(newsockfd, "SERVER: ENTER GRADE IN SUBJECT 1- \n", strlen("SERVER: ENTER GRADE IN SUBJECT 1- ")) < 0)
    {
        printf("error in writing for grade 1\n");
        return -1;
    }
    if (n = read(newsockfd, &grade1, sizeof(int)) < 0)
    {
        printf("error in reading grade 1\n");
        return -1;
    }
    ////////////////////////////////////

    if (n = write(newsockfd, "SERVER: ENTER GRADE IN SUBJECT 2- \n", strlen("SERVER: ENTER GRADE IN SUBJECT 2- ")) < 0)
    {
        printf("error in writing for grade 2/n");
        return -1;
    }
    if (n = read(newsockfd, &grade2, sizeof(int)) < 0)
    {
        printf("error in reading grade 2\n");
        return -1;
    }
    /////////////////////////////////////

    if (n = write(newsockfd, "SERVER: ENTER GRADE IN SUBJECT 3- \n", strlen("SERVER: ENTER GRADE IN SUBJECT 3- ")) < 0)
    {
        printf("error in writing for grade 3\n");
        return -1;
    }
    if (n = read(newsockfd, &grade3, sizeof(int)) < 0)
    {
        printf("error in reading grade 3\n");
        return -1;
    }
    /////////////

    char val1, val2, val3;
    val1 = grader(grade1);
    val2 = grader(grade2);
    val3 = grader(grade3);

    if (n = write(newsockfd, "SERVER: Subject 1- ", strlen("SERVER: Subject 1- ")) < 0)
    {
        printf("Error in displaying val1");
        return -1;
    }
    write(newsockfd, (char *)&val1, sizeof(char));
    if (n = write(newsockfd, "SERVER: Subject 2- ", strlen("SERVER: Subject 2- ")) < 0)
    {
        printf("Error in displaying val2");
        return -1;
    }
    write(newsockfd, (char *)&val2, sizeof(char));
    if (n = write(newsockfd, "SERVER: Subject 3- ", strlen("SERVER: Subject 3- ")) < 0)
    {
        printf("Error in displaying val3");
        return -1;
    }
    write(newsockfd, (char *)&val3, sizeof(char));

    close(sockfd);
    close(newsockfd);

    return 0;
}