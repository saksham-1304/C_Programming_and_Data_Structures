// Storage Class Auto--Automatic Variables

#include <stdio.h>
int multiply(int x, int y)
{
    x *= y;
    return x;
}
int main()
{
    int a, b, c;
    a = 2;
    b = 5;
    c = multiply(a, b);
    a = multiply(b, c);
    printf("%d %d %d", a, b, c);
    return 0;
}