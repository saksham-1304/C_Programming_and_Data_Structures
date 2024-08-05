#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char str1[] = "DA104";
    char str2[] = {'D', 'A', '1', '0', '4'};
    int n1 = sizeof(str1) / sizeof(str1[0]);
    int n2 = strlen(str1) / sizeof(str1[0]);
    int n3 = sizeof(str2) / sizeof(str2[0]);
    printf("n1=%d,n2=%d,n3=%d\n", n1, n2, n3);
    return 0;
}