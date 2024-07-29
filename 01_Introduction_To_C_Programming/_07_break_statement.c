// Break Statement

// Write a program which read an integer from the user .If the number is positive,it prints "I am positive" and again reads a new value.Otherwise the program exits with a message

#include <stdio.h>
int main()
{
    int counter;
    while (1)
    {
        scanf("%d", &counter);
        if (counter < 0)
        {
            printf("I am not a positive\n");
            break;
        }
        else
        {
            printf("I am positve\n");
        }
    }
}