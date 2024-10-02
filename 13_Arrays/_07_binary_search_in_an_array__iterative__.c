// Binary Search In An Array-->Iterative

#include <stdio.h>

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (key > arr[mid]) // Go to the right part
        {
            start = mid + 1;
        }
        else // Go to the left part
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int even[6] = {2, 4, 6, 8, 12, 18};
    int odd[5] = {3, 8, 11, 14, 16};
    
    int evenindex = binarySearch(even, 6, 12);
    printf("Index of 12 is %d\n", evenindex);
    
    int oddindex = binarySearch(odd, 5, 8);
    printf("Index of 8 is %d\n", oddindex);

    return 0;
}
