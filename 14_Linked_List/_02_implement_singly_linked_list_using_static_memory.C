#include <stdio.h>
struct node
{
    int info;
    int next;
};
int main()
{
    int a[10][2], head = 5;
    struct node list[10];
    list[head].info = 3;
    list[head].next = 2;
    list[list[head].next].info = 1;
    list[list[head].next].next = 8;
    list[list[list[head].next].next].info = 7;
    list[list[list[head].next].next].next = -1;
    printf("First Element: %d\n", list[head].info);
    printf("Second Element: %d\n", list[list[head].next].info);
    printf("Third Element: %d\n", list[list[list[head].next].next].info);
}