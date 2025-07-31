import random


def quick_sort_inplace(arr, left, right):
    if left >= right:
        return

    # Random pivot selection
    pivot_index = random.randint(left, right)
    pivot = arr[pivot_index]

    # Move pivot to end temporarily
    arr[pivot_index], arr[right] = arr[right], arr[pivot_index]

    i = left
    for j in range(left, right):
        if arr[j] <= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1

    # Move pivot to its correct position
    arr[i], arr[right] = arr[right], arr[i]

    # Recursively sort the left and right parts
    quick_sort_inplace(arr, left, i - 1)
    quick_sort_inplace(arr, i + 1, right)
