#include <stdio.h>

// Function to print the array
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Merge two sorted arrays into a single sorted array
void merger(int left[], int leftsize, int right[], int rightsize, int arr[])
{
    int i = 0, j = 0, k = 0;
    while (i < leftsize && j < rightsize)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }
    while (i < leftsize)
    {
        arr[k++] = left[i++];
    }
    while (j < rightsize)
    {
        arr[k++] = right[j++];
    }
}

// Recursive merge sort function
void merge_sort(int arr[], int size)
{
    if (size <= 1)
        return;

    int mid = size / 2;
    int left[mid], right[size - mid];

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];
    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merger(left, mid, right, size - mid, arr);
}
/*
 * Merge Sort Algorithm
 * This is a divide and conquer algorithm that sorts an array by recursively dividing it into halves,
 * this is a recursive function that sorts the array in place.
 * we sort until we reach the base case of a single element, then we merge the sorted halves back together.
 * The merge function combines two sorted arrays into one sorted array.
 * runtime complexity: O(n log n)
 * space complexity: O(n)
 * uses more space than bubble sort, selection, insertion sort etc
 * but it is faster than those algorithms for larger arrays.
 */
int main()
{
    int arr[] = {12, 87, 54, 21, 58, 45, 32, 90, 11, 67};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, size);
    print(arr, size);
    return 0;
}
