// Fibonacci Series -Recursion

#include <stdio.h>
long fibonacci(long n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}
