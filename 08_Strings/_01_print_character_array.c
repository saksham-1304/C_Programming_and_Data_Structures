// Print Character Array

// Write a program ro print an array of characters

#include <stdio.h>
int main()
{
    char string[] = "This is a string";
    char *cptr = string;
    for (; *cptr != '\0'; cptr++)
    {
        printf("%c", *cptr);
    }
}