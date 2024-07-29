// Function To Add Two Numbers

#include <stdio.h>
int add(int x, int y)
{
    return x + y;
}
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("Sum is %d ", add(num1, num2));
}