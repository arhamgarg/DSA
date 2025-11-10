package main

func OrderAgnosticBinarySearch(arr []int, target int) int {
	if arr == nil || len(arr) == 0 {
		return -1
	}

	low := 0
	high := len(arr) - 1
	ascending := arr[low] < arr[high]

	for low <= high {
		mid := low + (high-low)/2

		if arr[mid] == target {
			return mid
		}

		if ascending {
			if target < arr[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		} else {
			if target > arr[mid] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		}
	}

	return -1
}
