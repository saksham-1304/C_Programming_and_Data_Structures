// String Length

#include <stdio.h>
#include <string.h>
int main()
{
    char str1[20] = "Programming";
    printf("Length of string str1: %lu\n", strlen(str1));
    printf("Length of string str1: %lu\n", strnlen(str1, 7));
    printf("Length of string str1: %lu\n", strnlen(str1, 31));
    char *str2 = "Hello World";
    printf("%lu\n", strlen(str2));
}