// Do-While Loop

#include <stdio.h>
int main()
{
    int number;
    do
    {
        printf("Enter a number");
        scanf("%d", &number);

    }

    while (number < 0);
    printf("You Entered a Positive Number\n");
    return 0;
}