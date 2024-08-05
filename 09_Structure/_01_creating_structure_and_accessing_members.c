// Creating Structure And Accessing Members

#include <stdio.h>
struct student
{
    char name[30];
    int roll_no;
};

int main()
{
    struct student stud1 = {"Alice", 100};
    printf("Name: %s\n", stud1.name);
    printf("Roll no: %d\n", stud1.roll_no);
}