/*
Write a function "sum" that keeps a running total of the sum of every value passed to "sum"
Input 1 2 3 4 5...EOF
Output: 1 3 6 10 15...

The program should keep on reading values till the user inputs EOF
*/

#include <stdio.h>
int sum(int value)
{
    static int sum = 0; // Static Variable
    sum += value;
    return sum;
}
void main()
{
    int value;
    scanf("%d", &value);
    while (value != EOF)
    {
        printf("Running Sum:%d\n", sum(value));
        scanf("%d", &value);
    }
}