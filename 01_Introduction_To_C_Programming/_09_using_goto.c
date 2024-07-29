// Using Goto

#include <stdio.h>
int main()
{
begin:
    for (int i = 1; i <= 10; i++)
    {
        if (i == 5)
        {
            goto begin;
        }
        printf("%d", i);
    }
}