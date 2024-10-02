// Binary Search In An Array-->Recursive

#include <stdio.h>

int binarySearchRecursive(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return -1; // Key not found
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid; // Key found
    }
    else if (key > arr[mid])
    {
        return binarySearchRecursive(arr, mid + 1, end, key); // Search in the right part
    }
    else
    {
        return binarySearchRecursive(arr, start, mid - 1, key); // Search in the left part
    }
}

int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};
    
    int evenindex = binarySearchRecursive(even, 0, 5, 12);
    printf("Index of 12 is %d\n", evenindex);
    
    int oddindex = binarySearchRecursive(odd, 0, 4, 8);
    printf("Index of 8 is %d\n", oddindex);

    return 0;
}
