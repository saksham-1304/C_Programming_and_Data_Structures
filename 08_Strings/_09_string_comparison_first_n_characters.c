// String Comparison:First N Characters

#include <stdio.h>
#include <string.h>
int main()
{
    char s1[30] = "Programming Computer";
    char s2[30] = "Programming";
    if (strncmp(s1, s2, 11) == 0)
    {
        printf("String 1 and string 2 are equal");
    }
    else
    {
        printf("String 1 and 2 are different");
    }
    return 0;
}