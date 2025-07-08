package main

import "fmt"

func selectionSort(arr []int) {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		minIndex := i

		for j := i + 1; j < n; j++ {
			if arr[j] < arr[minIndex] {
				minIndex = j
			}
		}
		
		arr[i], arr[minIndex] = arr[minIndex], arr[i]
	}
}

func main() {
	arr := []int{4, 1, 47, 64, 23, 6, 37,69}

	selectionSort(arr)
	fmt.Println("Sorted array:  ", arr)
}
