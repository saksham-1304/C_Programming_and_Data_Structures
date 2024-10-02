//Sparse Matrix Using Arrays

#include <stdio.h>
int main()
{
    int row1, col1;
    printf("Enter the number of rows and columns for first matrix\n");
    scanf("%d %d", &row1, &col1);

    // Matrix Input
    int mat1[row1][col1];
    printf("Enter the elements row-wise\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    int row2, col2;
    printf("Enter the number of rows and columns for second matrix\n");
    scanf("%d %d", &row2, &col2);

    // Matrix Input
    int mat2[row2][col2];
    printf("Enter the elements row-wise\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Convert first matrix to sparse matrix format
    int count1 = 0;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            if (mat1[i][j] != 0)
            {
                count1++;
            }
        }
    }

    int sparse1[count1][3];
    int k = 0;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            if (mat1[i][j] != 0)
            {
                sparse1[k][0] = i;
                sparse1[k][1] = j;
                sparse1[k][2] = mat1[i][j];
                k++;
            }
        }
    }

    // Convert second matrix to sparse matrix format
    int count2 = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            if (mat2[i][j] != 0)
            {
                count2++;
            }
        }
    }

    int sparse2[count2][3];
    k = 0;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            if (mat2[i][j] != 0)
            {
                sparse2[k][0] = i;
                sparse2[k][1] = j;
                sparse2[k][2] = mat2[i][j];
                k++;
            }
        }
    }

    // Display Sparse Matrices
    printf("Sparse Matrix 1\n");
    for (int i = 0; i < count1; i++)
    {
        printf("%d %d %d\n", sparse1[i][0], sparse1[i][1], sparse1[i][2]);
    }
    printf("Sparse Matrix 2\n");
    for (int i = 0; i < count2; i++)
    {
        printf("%d %d %d\n", sparse2[i][0], sparse2[i][1], sparse2[i][2]);
    }

    // Adding Two Sparse Matrices
    int sparseSum[count1 + count2][3]; // Maximum possible size
    int i = 0, j = 0, l = 0;

    while (i < count1 && j < count2)
    {
        if (sparse1[i][0] < sparse2[j][0] ||
            (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] < sparse2[j][1]))
        {
            sparseSum[l][0] = sparse1[i][0];
            sparseSum[l][1] = sparse1[i][1];
            sparseSum[l][2] = sparse1[i][2];
            i++;
        }
        else if (sparse1[i][0] > sparse2[j][0] ||
                 (sparse1[i][0] == sparse2[j][0] && sparse1[i][1] > sparse2[j][1]))
        {
            sparseSum[l][0] = sparse2[j][0];
            sparseSum[l][1] = sparse2[j][1];
            sparseSum[l][2] = sparse2[j][2];
            j++;
        }
        else
        {
            sparseSum[l][0] = sparse1[i][0];
            sparseSum[l][1] = sparse1[i][1];
            sparseSum[l][2] = sparse1[i][2] + sparse2[j][2];
            i++;
            j++;
        }
        l++;
    }

    while (i < count1)
    {
        sparseSum[l][0] = sparse1[i][0];
        sparseSum[l][1] = sparse1[i][1];
        sparseSum[l][2] = sparse1[i][2];
        i++;
        l++;
    }

    while (j < count2)
    {
        sparseSum[l][0] = sparse2[j][0];
        sparseSum[l][1] = sparse2[j][1];
        sparseSum[l][2] = sparse2[j][2];
        j++;
        l++;
    }

    printf("Resultant Sparse Matrix \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d %d %d\n", sparseSum[i][0], sparseSum[i][1], sparseSum[i][2]);
    }

    // Transpose of Sparse Matrix
    for (int i = 0; i < l; i++)
    {
        int temp = sparseSum[i][0];
        sparseSum[i][0] = sparseSum[i][1];
        sparseSum[i][1] = temp;
    }

    printf("Transpose of Resultant Sparse Matrix \n");
    for (int i = 0; i < l; i++)
    {
        printf("%d %d %d\n", sparseSum[i][0], sparseSum[i][1], sparseSum[i][2]);
    }

    // Multiplication of sparse matrices
    if (col1 != row2)
    {
        printf("Matrix multiplication not possible as the number of columns of the first matrix is not equal to the number of rows of the second matrix.\n");
        return 0;
    }

    // Multiplication process
    int sparseProduct[count1 * count2][3]; // Maximum possible size
    int p = 0;

    for (int i = 0; i < count1; i++)
    {
        for (int j = 0; j < count2; j++)
        {
            if (sparse1[i][1] == sparse2[j][0]) // column of sparse1 matches row of sparse2
            {
                int row = sparse1[i][0];
                int col = sparse2[j][1];
                int value = sparse1[i][2] * sparse2[j][2];

                // Check if the position already exists in the result and add values if it does
                int found = 0;
                for (int l = 0; l < p; l++)
                {
                    if (sparseProduct[l][0] == row && sparseProduct[l][1] == col)
                    {
                        sparseProduct[l][2] += value;
                        found = 1;
                        break;
                    }
                }

                // If position doesn't exist, add a new entry
                if (!found)
                {
                    sparseProduct[p][0] = row;
                    sparseProduct[p][1] = col;
                    sparseProduct[p][2] = value;
                    p++;
                }
            }
        }
    }

    // Display Product Sparse Matrix
    printf("Resultant Sparse Matrix after Multiplication\n");
    for (int i = 0; i < p; i++)
    {
        printf("%d %d %d\n", sparseProduct[i][0], sparseProduct[i][1], sparseProduct[i][2]);
    }

    return 0;
}
