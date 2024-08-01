// String Comparison

#include <stdio.h>
#include <string.h>
int main()
{
    char s1[30] = "Programming";
    char s2[30] = "Programming Computer";
    if (strcmp(s1, s2) == 0)
    {
        printf("String 1 and String 2 are equal");
    }
    else
    {
        printf("String 1 and 2 are different");
        return 0;
    }
}
