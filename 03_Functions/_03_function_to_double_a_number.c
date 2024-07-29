// Function To a Double A Number

#include <stdio.h>
void twice(int x)
{
    x = x * 2;
    printf("x in function:%d\n", x);
}
int main()
{
    int x = 10;
    printf("x in main: %d\n", x);
    twice(x);
    printf("x in main: %d\n", x);
}
