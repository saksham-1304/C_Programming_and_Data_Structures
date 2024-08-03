// Passing Arguments To Main Function

#include <stdio.h>
int main(int argc, char *argv[])
{
    int i;
    printf("%d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}