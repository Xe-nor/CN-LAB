#include <stdio.h>


struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

void aggregate(struct pkt packet)
{
    int num, remainder, i = 1;
    printf("Enter a number :");
    scanf("%d", &num);
    while (num != 0 && i <= 4)
    {
        remainder = num % 10;
        if (i == 1)
            packet.ch1 = remainder;

        if (i == 2)
            packet.ch2[0] = remainder;

        if (i == 3)
            packet.ch2[1] = remainder;

        if (i == 4)
            packet.ch3 = remainder;
        i++;
        num = num / 10;
    }
    printf("\nThe aggregeated characters are %d %d %d %d ", packet.ch3, packet.ch2[1], packet.ch2[0], packet.ch1);
    printf("\nThe orignal no. is %d%d%d%d", packet.ch3, packet.ch2[1], packet.ch2[0], packet.ch1);
}

int main()
{
    struct pkt packet;
    aggregate(packet);
}