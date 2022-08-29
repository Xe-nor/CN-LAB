#include <stdio.h>
#include <string.h>

struct student
{
    int roll;
    char name[20];
    float cgpa;
};

void func(struct student *record);

int main()
{
    struct student record;

    record.roll = 1;
    strcpy(record.name, "Raju");
    record.cgpa = 8.5;

    func(&record);
    return 0;
}

void func(struct student *record)
{
    printf(" roll is: %d \n", *record.roll);
    printf(" Name is: %s \n", *record.name);
    printf(" cgpa is: %f \n", *record.cgpa);
}