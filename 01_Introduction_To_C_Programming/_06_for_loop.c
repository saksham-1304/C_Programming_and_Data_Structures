// For Loop
//Print Odd Number From 1 to n

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 2)
    {
        printf("%d\n", i);
    }
}