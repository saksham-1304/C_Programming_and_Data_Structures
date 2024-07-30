// Storage Class Static
// Write a program to count the number of times a function is called

#include <stdio.h>
int f()
{
    static int cnt = 0;
    ++cnt;
    return cnt;
}
int main()
{
    printf("%d\n", f());
    printf("%d\n", f());
    printf("%d\n", f());
    printf("%d\n", f());
    printf("%d\n", f());
}