// Dynamic Memory Allocation

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    float *p;
    scanf("%d", &n);
    p = malloc(n * sizeof(float));
    if (p == NULL)
    {
        printf("Failed\n");
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%f", p + i);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", *(p + i));
    }
}