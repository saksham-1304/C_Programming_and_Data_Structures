// Write a program to check whether a matrix is an upper triangular matrix or not

#include <stdio.h>
#define row 3
#define col 3
int main()
{
    int arr[row][col] = {{1, 2, 3}, {0, 4, 5}, {0, 0, 6}};
    int isUpper = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j < i && arr[i][j] != 0)
            {
                isUpper = 0;
            }
        }
    }
    if (isUpper)
    {
        printf("Matrix is upper triangular\n");
    }
    else
    {
        printf("Matrix is not upper triangular\n");
    }
}
