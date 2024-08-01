// String Concatenation Limited To Maxlen

#include <stdio.h>
#include <string.h>
int main()
{
    char s1[10] = "Hello";
    char s2[10] = "World";
    strncat(s1, s2, 3);
    // Concatenates n characters of srt2 to str1
    printf("Output %s", s1);
    return 0;
}