// Find a number in a given collection of integer numbers

#include <stdio.h>
int main()
{
    int find = 10;
    int collection[] = {3, 10, 4, 6, 7};
    int i;
    for ( i = 0; i < 5; i++)
    {
        if (collection[i] == find)
        {
            break;
        }

    }
    if (i < 5)
    {
        printf("Found");
    }

    else
    {
        printf("Not Found");
    }
}