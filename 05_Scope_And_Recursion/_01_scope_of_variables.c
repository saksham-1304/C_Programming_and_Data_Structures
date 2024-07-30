// Scope Of Variables

#include <stdio.h>
int main()
{
    int a = 1, b = 2, c = 3;
    printf("%d %d %d\n", a, b, c);
    {
        int b = 4;
        float c = 5.0;
        printf("%d,%d,%f\n", a, b, c);
        a = b;
        {
            int c;
            c = b;
            printf("%d,%d,%d\n", a, b, c);
        }
        printf("%d,%d,%f\n", a, b, c);
    }
    printf("%d,%d,%d\n", a, b, c);
}