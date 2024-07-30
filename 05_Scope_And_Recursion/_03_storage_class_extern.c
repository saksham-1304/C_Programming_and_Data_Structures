// Storage Class Extern

#include <stdio.h>
int a = 1,b = 2,c = 3; // Global Variables
int f()
{
    int b, c;
    a = b = c = 4;
    return (a + b + c);
}
int main()
{
    printf("%d\n", f());
    printf("%d %d %d", a, b, c);
    return 0;
}
