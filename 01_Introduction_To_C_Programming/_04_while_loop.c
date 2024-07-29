// Write a progrom that takes as input a number n from the user .If the number is greater than 0 ,it prints all the numbers from 1 to n

#include <stdio.h>
int main()
{
    int n, cnt = 1;
    scanf("%d", &n);
    while (n > 0)
    {
        printf("%d\n", cnt);
        cnt++;
        n--;
    }
    return 0;
}