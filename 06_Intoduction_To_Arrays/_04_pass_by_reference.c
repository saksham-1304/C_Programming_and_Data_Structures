// Pass by reference

#include <stdio.h>
#define SIZE 3
void fun(int b[], int s)
{
    if (s == 3)
    {
        b[s - 3] = b[s - 2] + b[s - 1];
    }
}
int main()
{
    int a[SIZE] = {1, 2, 3};
    fun(a, 3);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}