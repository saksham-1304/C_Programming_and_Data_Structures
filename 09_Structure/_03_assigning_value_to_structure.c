// Assigning Value to Structure

#include <stdio.h>
typedef struct
{
    char name[30];
    int roll_no;
} student;
int main()
{
    student stud1 = {"Alice", 123}, stud2;
    stud2 = stud1;
    printf("%s\n", stud2.name);
}
