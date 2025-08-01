#include <stdio.h>
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insertion_sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    print(arr, size);
    return 0;
}
int main()
{
    int arr[] = {12, 87, 54, 21, 58, 45, 32, 90, 11, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, size);
    return 0;
}