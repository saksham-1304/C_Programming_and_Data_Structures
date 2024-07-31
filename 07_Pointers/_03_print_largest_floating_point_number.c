// Print Largest Floating Point Number

// Write a program that accepts n floating point numbers from the  user and prints the largest element. [use calloc() for dynamic memmory allocation]

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d", &n);
    float *p = (float *)calloc(n, sizeof(int)), max = 0.0;
    for (int i = 0; i < n; i++)
    {
        scanf("%f", p + i);
        if (*(p + i) > max)
        {
            max = *(p + i);
        }
    }
    printf("Max: %0.3f\n", max);
}