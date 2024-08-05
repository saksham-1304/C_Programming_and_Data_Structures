/*
Write a program to store all the course details of all the students iny your class.
There are 250 students
    ->Store their name and roll number
    ->Each student enrols in 4 courses
    ->For each course we need to record the course code,course name and the marks scored int that course
*/

#include <stdio.h>
typedef struct
{
    char c_code[5];
    char c_name[20];
    float marks;
} course;

typedef struct
{
    char s_name[30];
    int roll_no;
    course subjects[4];

} student;
student bsc_student[250];

int main()
{
    for (int i = 0; i < 2; i++)
    {
        scanf("%s", bsc_student[i].s_name);
        scanf("%d", &bsc_student[i].roll_no);
        for (int j = 0; j < 4; j++)
        {
            scanf("%s", bsc_student[i].subjects[j].c_code);
            scanf("%s", bsc_student[i].subjects[j].c_name);
            scanf("%f", &bsc_student[i].subjects[j].marks);
        }
    }
}