// Convert LowerCase To UpperCase

#include <stdio.h>
int main()
{
    int c;
    for (;;)
    {
        c = getchar();
        if (c == EOF)
        {
            break;
        }
        if (c >= 97 && c < 123)
        {
            c -= 32;
            putchar(c);
        }
    }
}