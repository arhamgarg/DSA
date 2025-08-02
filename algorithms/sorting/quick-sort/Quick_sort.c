#include <stdio.h>

void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;
    return i;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(arr, start, end);
    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot + 1, end);
}

/* Quick-sort
 * first we pick a pivot
 * mostly the last address
 * the pivot value acts as checker whether the values from the start compared by i(before j) and j(start of the array)
 * we check whether the value of j is less than our pivot, if greater than or equal to the pivot we ignore it
 * we also have a temporary holder variable for changing the values
 * if the value of j is less than the pivot then we will swap values between i and j and using temporary variable
 * when the pivot index is equal to j then swap variables between i and j
 * the values to the left and right of the pivot may not be necessarily in order
 * but the numbers in the left and right are less than and greater then the pivot value respectively
 * now we create partitions without the pivot value
 * and pass the separated arrays into smaller arrays and then we
 * apply the same procedure on them
 */
int main()
{
    int arr[] = {12, 87, 54, 21, 58, 45, 32, 90, 11, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}