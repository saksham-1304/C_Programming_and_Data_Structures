//Matrix Multiplcation And Addition 

#include <stdio.h>

void matrixAddition(int rows, int cols, int mat1[10][10], int mat2[10][10], int result[10][10]) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void matrixMultiplication(int rows1, int cols1, int mat1[10][10], int rows2, int cols2, int mat2[10][10], int result[10][10]) 
{
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) 
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() 
{
    int rows1, cols1, rows2, cols2;
    int mat1[10][10], mat2[10][10], result[10][10];

    // Input dimensions
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    // Input matrices
    printf("Enter first matrix:\n");
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols1; j++) 
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter second matrix:\n");
    for (int i = 0; i < rows2; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Matrix addition
    if (rows1 == rows2 && cols1 == cols2) 
    {
        matrixAddition(rows1, cols1, mat1, mat2, result);
        printf("Matrix after addition:\n");
        for (int i = 0; i < rows1; i++) 
        {
            for (int j = 0; j < cols1; j++) 
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("Matrices can't be added as their dimensions don't match.\n");
    }

    // Matrix multiplication
    if (cols1 == rows2) 
    {
        matrixMultiplication(rows1, cols1, mat1, rows2, cols2, mat2, result);
        printf("Matrix after multiplication:\n");
        for (int i = 0; i < rows1; i++) 
        {
            for (int j = 0; j < cols2; j++) 
            {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    } 
    else 
    {
        printf("Matrices can't be multiplied as dimensions don't match.\n");
    }

    return 0;
}
