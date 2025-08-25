import random


class Sorting:
    @staticmethod
    def quick_sort_inplace(arr, left, right):
        if left >= right:
            return

        pivot_index = random.randint(left, right)
        pivot = arr[pivot_index]

        arr[pivot_index], arr[right] = arr[right], arr[pivot_index]

        i = left
        for j in range(left, right):
            if arr[j] <= pivot:
                arr[i], arr[j] = arr[j], arr[i]
                i += 1

        arr[i], arr[right] = arr[right], arr[i]

        Sorting.quick_sort_inplace(arr, left, i - 1)
        Sorting.quick_sort_inplace(arr, i + 1, right)
