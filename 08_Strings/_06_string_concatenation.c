// String Concatenation

#include <stdio.h>
#include <string.h>
int main()
{
    char s1[10] = "Hello";
    char s2[10] = "World";
    strcat(s1, s2);
    printf("Output %s", s1);
    return 0;
}