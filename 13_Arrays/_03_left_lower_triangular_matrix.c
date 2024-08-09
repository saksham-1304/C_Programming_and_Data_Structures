#include <stdio.h>
int main()

{
    int i, j, k = 0, n = 5;
    int B[25];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i >= j)
            {
                scanf("%d", &B[k]);
                k++;
            }
        }
    }
}