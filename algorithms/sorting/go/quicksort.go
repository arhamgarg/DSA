package main

import "fmt"

func quickSort(arr []int, low, high int) {
	if low < high {
		pivotIndex := partition(arr, low, high)

		// Recursively sort left and right of the pivot
		quickSort(arr, low, pivotIndex-1)
		quickSort(arr, pivotIndex+1, high)
	}
}

func partition(arr []int, low, high int) int {
	// Implemented where pivot element is last element
	pivot := arr[high]
	i := low - 1 // index of smaller element

	for j := low; j < high; j++ {
		if arr[j] < pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}

	// Swap pivot to correct position
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}

func main() {
	arr := []int{4, 1, 47, 64, 23, 6, 37,69}

	quickSort(arr, 0, len(arr)-1)
	fmt.Println("Sorted array: ", arr)
}
