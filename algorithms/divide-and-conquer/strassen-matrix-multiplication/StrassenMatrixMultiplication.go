package main

import (
	"fmt"
)

// given 2 matrices A and B: return A + B
func add(A, B [][]int) [][]int {
	n := len(A)
	C := make([][]int, n)

	for i := range C {
		C[i] = make([]int, n)
		for j := range C[i] {
			C[i][j] = A[i][j] + B[i][j]
		}
	}
	return C
}

// given 2 matrices A and B: return A - B
func subtract(A, B [][]int) [][]int {
	n := len(A)
	C := make([][]int, n)

	for i := range C {
		C[i] = make([]int, n)
		for j := range C[i] {
			C[i][j] = A[i][j] - B[i][j]
		}
	}
	return C
}

// given 2 matrices A and B: return A X B (Strassen)
func Strassen(A, B [][]int) [][]int {
	n := len(A)

	// base case: single element multiplication
	if n == 1 {
		return [][]int{{A[0][0] * B[0][0]}}
	}

	k := n / 2

	// divide matrices into 4 parts each
	A11 := make([][]int, k)
	A12 := make([][]int, k)
	A21 := make([][]int, k)
	A22 := make([][]int, k)

	B11 := make([][]int, k)
	B12 := make([][]int, k)
	B21 := make([][]int, k)
	B22 := make([][]int, k)

	// allocate space for sub matrices
	for i := 0; i < k; i++ {
		A11[i] = make([]int, k)
		A12[i] = make([]int, k)
		A21[i] = make([]int, k)
		A22[i] = make([]int, k)

		B11[i] = make([]int, k)
		B12[i] = make([]int, k)
		B21[i] = make([]int, k)
		B22[i] = make([]int, k)

		// fill sub matrices
		for j := 0; j < k; j++ {
			A11[i][j] = A[i][j]
			A12[i][j] = A[i][j+k]
			A21[i][j] = A[i+k][j]
			A22[i][j] = A[i+k][j+k]

			B11[i][j] = B[i][j]
			B12[i][j] = B[i][j+k]
			B21[i][j] = B[i+k][j]
			B22[i][j] = B[i+k][j+k]
		}
	}

	// compute the 7 products (core idea of Strassen)
	P1 := Strassen(A11, subtract(B12, B22))
	P2 := Strassen(add(A11, A12), B22)
	P3 := Strassen(add(A21, A22), B11)
	P4 := Strassen(A22, subtract(B21, B11))
	P5 := Strassen(add(A11, A22), add(B11, B22))
	P6 := Strassen(subtract(A12, A22), add(B21, B22))
	P7 := Strassen(subtract(A11, A21), add(B11, B12))

	// merge partial results into final quadrants
	C11 := add(subtract(add(P5, P4), P2), P6)
	C12 := add(P1, P2)
	C21 := add(P3, P4)
	C22 := subtract(subtract(add(P1, P5), P3), P7)

	C := make([][]int, n)

	// place each quadrant into result matrix
	for i := 0; i < k; i++ {
		C[i] = make([]int, n)
		copy(C[i][:k], C11[i])
		copy(C[i][k:], C12[i])

		C[i+k] = make([]int, n)
		copy(C[i+k][:k], C21[i])
		copy(C[i+k][k:], C22[i])
	}

	return C
}
