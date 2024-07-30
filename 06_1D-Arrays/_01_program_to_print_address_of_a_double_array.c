// Address Of Arrays

// 1.Write a program to print the address of a double array to show that elements of the array are stored sequentially
// 2.Print the length

#include <stdio.h>
#define SIZE 4
int main()
{
    double mark[SIZE];
    int i;
    printf("Size of double is %lu\n", sizeof(double));
    for (int i = 0; i < SIZE; i++)
    {
        printf("Address of mark[%d] is %p\n", i, &mark[i]);
    }
}