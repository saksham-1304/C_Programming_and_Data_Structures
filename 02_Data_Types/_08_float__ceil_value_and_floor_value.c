// Write a program that accepts a floating point number and prints the ceiling and floor value of the number.You should not use any staandard function
//
#include <stdio.h>
int main()
{
    float i;
    scanf("%f", &i);
    int floor = (int)(i);
    int ceil = floor + 1;
    printf("%d\n", floor);
    printf("%d\n", ceil);
    return 0;
}