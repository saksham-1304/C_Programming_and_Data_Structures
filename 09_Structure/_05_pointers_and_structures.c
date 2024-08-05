// Pointers Andd Structures

/*Write a structure to store student records
    Read input and print output using pointers to the struture
*/

#include <stdio.h>
struct student
{
    char name[30];
    int roll_no;
    float marks;
} bsc_students[2], *ptr;
int main()
{
    ptr = bsc_students;
    for (int i = 0; i < 2; i++)
    {
        scanf("%s", ptr->name);
        scanf("%d", &ptr->roll_no);
        scanf("%f", &(*ptr).marks);
        ptr++;
    }
    ptr = bsc_students;
    for (int i = 0; i < 2; i++)
    {
        printf("%s\t", ptr->name);
        printf("%d\t", ptr->roll_no);
        printf("%f\n", (*ptr).marks);
        ptr++;
    }
}