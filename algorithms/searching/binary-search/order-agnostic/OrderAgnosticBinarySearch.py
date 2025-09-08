def order_agnostic_binary_search(arr, target):
    if not arr:
        return -1
    start, end = 0, len(arr) - 1
    ascending = arr[start] < arr[end]
    while start <= end:
        mid = start + (end - start) // 2
        if arr[mid] == target:
            return mid
        if ascending:
            if target < arr[mid]:
                end = mid - 1
            else:
                start = mid + 1
        else:
            if target > arr[mid]:
                end = mid - 1
            else:
                start = mid + 1
    return -1
