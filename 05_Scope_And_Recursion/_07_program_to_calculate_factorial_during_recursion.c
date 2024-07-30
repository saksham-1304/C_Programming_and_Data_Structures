// Factorial During Recursion

#include <stdio.h>
int factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1; // Base Case
    }
    else
    {
        return n * factorial(n - 1);
    }
}
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("Factorial of n is: %d\n", factorial(n));
    return 0;
}