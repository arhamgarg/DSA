package main

import "fmt"

func mergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	// divide
	mid := len(arr) / 2
	left := mergeSort(arr[:mid])
	right := mergeSort(arr[mid:])

	// conquer
	return merge(left, right)
}

func merge(left, right []int) []int {
	result := []int{}
	i, j := 0, 0

	// Merge two sorted slices
	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			j++
		}
	}

	// Append remaining elements
	result = append(result, left[i:]...)
	result = append(result, right[j:]...)

	return result
}

func main() {
	arr := []int{4, 1, 47, 64, 23, 6, 37,69}

	sorted := mergeSort(arr)
	fmt.Println("Sorted array: ", sorted)
}
