// String Copy

#include <stdio.h>
#include <string.h>
int main()
{
    char s1[30] = "Hello";
    char s2[30] = "Computer Programming";
    strcpy(s1, s2);
    printf("String s1 is %s", s1);
    
    return 0;
}
