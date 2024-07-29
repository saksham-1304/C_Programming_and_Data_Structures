// Continue Statement

// Write a program which read an integer from the user .If the number is positive,it prints "I am positive" and again reads a new value.Otherwise the program continues

#include <stdio.h>
int main()
{
    int counter;
    while (1)
    {
        scanf("%d", &counter);
        if (counter < 0)
        {
            continue;
        }
        else
        {
            printf("I am positve\n");
        }
    }
}