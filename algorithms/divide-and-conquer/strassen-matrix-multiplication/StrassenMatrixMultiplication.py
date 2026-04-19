# given 2 matrices A and B: return A + B
def add(A, B):
    return [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]


# given 2 matrices A and B: return A - B
def subtract(A, B):
    return [[A[i][j] - B[i][j] for j in range(len(A[0]))] for i in range(len(A))]


# given 2 matrices A and B: return A X B (Strassen)
def strassen(A, B):
    n = len(A)

    # base case: single element multiplication
    if n == 1:
        return [[A[0][0] * B[0][0]]]

    k = n // 2

    # divide matrices into 4 parts each
    A11 = [row[:k] for row in A[:k]]
    A12 = [row[k:] for row in A[:k]]
    A21 = [row[:k] for row in A[k:]]
    A22 = [row[k:] for row in A[k:]]

    B11 = [row[:k] for row in B[:k]]
    B12 = [row[k:] for row in B[:k]]
    B21 = [row[:k] for row in B[k:]]
    B22 = [row[k:] for row in B[k:]]

    # compute the 7 products (core idea of Strassen)
    P1 = strassen(A11, subtract(B12, B22))
    P2 = strassen(add(A11, A12), B22)
    P3 = strassen(add(A21, A22), B11)
    P4 = strassen(A22, subtract(B21, B11))
    P5 = strassen(add(A11, A22), add(B11, B22))
    P6 = strassen(subtract(A12, A22), add(B21, B22))
    P7 = strassen(subtract(A11, A21), add(B11, B12))

    # merge partial results into final quadrants
    C11 = add(subtract(add(P5, P4), P2), P6)
    C12 = add(P1, P2)
    C21 = add(P3, P4)
    C22 = subtract(subtract(add(P1, P5), P3), P7)

    C = []

    # place each quadrant into result matrix
    for i in range(k):
        C.append(C11[i] + C12[i])
    for i in range(k):
        C.append(C21[i] + C22[i])

    return C


if __name__ == "__main__":

    # sample 4 x 4 matrix input
    A = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]

    B = [[17, 18, 19, 20], [21, 22, 23, 24], [25, 26, 27, 28], [29, 30, 31, 32]]

    # perform strassen multiplication
    result = strassen(A, B)

    print("Resulting Matrix:")

    # print matrix row by row
    for row in result:
        print(row)
