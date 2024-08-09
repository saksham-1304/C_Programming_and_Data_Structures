#include <stdio.h>
#define SIZE 3

void fun(int a, int b, int c)
{
    c = a + b;
}
int main()
{
    int a[SIZE] = {1, 2, 3};
    fun(a[0], a[1], a[2]);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}