// Recursive HandShake Problem

// Write a recursive function to solve the handshake problem

#include <stdio.h>
int h(int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    // No handshakes possible with 0 or 1 person
    else
    {
        return h(n - 1) + n - 1;
    }
}
int main()
{
    int n;
    printf("Enter no. of persons: ");
    scanf("%d", &n);
    printf("Total handshakes: %d\n", h(n));
    return 0;
}