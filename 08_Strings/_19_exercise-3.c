#include <stdio.h>
#include <string.h>
int main()
{
    char str[20];
    char *str1 = "DA104";
    int length = strlen(str1);
    for (int i = 0; i < length; i++)
    {
        str[i] = str1[length - i - 1];
    }
    printf("%s", str);
}