// Read and Writing Character

#include <stdio.h>
int main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    // Different Ways Of Writing The Same

    // 1.

    /*
    for (c = getchar(); c != EOF; c = getchar())
    {
        putchar(c);
    }
    */

    // 2.

    /*
    for (;;)
    {
        c = getchar();
        if (c == EOF)
        {
            break;
            puchar(c);
        }
    }
    */

    // 3.

    /*
    c = getchar();
    while (c != EOF)
    {
        putchar(c);
        c = getchar();
    }
    */
}