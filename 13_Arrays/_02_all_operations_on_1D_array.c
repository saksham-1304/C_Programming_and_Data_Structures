#include <stdio.h>
int search(int A[], int ele, int n)
{
    /* check every element in the collection */
    for (int i = 0; i < n; i++)
    {
        if (A[i] == ele)
            return i;
    }
    return -1;
}
void insert(int *A, int ele, int i, int *n)
{
    int j;
    for (j = *n; j > i; j--)
    {
        A[j] = A[j - 1];
    }
    A[i] = ele;
    *n = *n + 1;
}
void delete(int *A, int i, int *n)
{
    int j;
    for (j = i; j < *n - 1; j++)
    {
        A[j] = A[j + 1];
    }
    *n = *n - 1;
}
void update(int *A, int i, int ele)
{
    A[i] = ele;
}
int main()
{
    int n = 5;
    int A[] = {3, 10, 4, 6, 7};
    printf("%d", search(A, 10, n));
    insert(A, 15, 3, &n);
    delete (A, 2, &n);
    display(A, n);
}