// Improper Use Of Macrosd

#include <stdio.h>
#define sq(x) x*x
//#define sq(x) (x*x)
//If You Use This without bracket it will return 25
int main()
{
    int x;
    x = 25 / sq(5);
    printf("%d", x);
    return 0;
}