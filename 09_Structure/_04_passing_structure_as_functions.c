#include <stdio.h>
#include <string.h>
struct student
{
    char name[10];
    int roll_no;
};

struct student createStudent(const char *name, int roll_no)
{
    struct student newStudent;
    strncpy(newStudent.name, name, sizeof(newStudent.name));
    newStudent.roll_no = roll_no;
    return newStudent;
}

void printStudent(struct student s)
{
    printf("Name %s\n", s.name);
    printf("Roll no %d\n", s.roll_no);
}

int main()
{
    struct student stud1 = createStudent("Alice", 1234);
    printStudent(stud1);
}
