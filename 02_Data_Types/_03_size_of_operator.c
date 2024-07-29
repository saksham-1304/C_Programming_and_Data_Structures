// Size Of Operator

#include <stdio.h>
int main()
{
    typedef char character;
    character a, b;
    printf("Size Of character:%lu\n", sizeof(character));
    printf("Size Of expression:%lu\n", sizeof(a + b));
    printf("Size of int:%lu\n", sizeof(int));
    printf("Size of float:%lu\n", sizeof(float));
    printf("Size of double:%lu\n", sizeof(double));
    printf("Size of long double:%lu\n", sizeof(long double));
}