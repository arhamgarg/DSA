class MatrixMultiplication:
    @staticmethod
    def add(A, B):
        return [[A[i][j] + B[i][j] for j in range(len(A[0]))] for i in range(len(A))]

    @staticmethod
    def subtract(A, B):
        return [[A[i][j] - B[i][j] for j in range(len(A[0]))] for i in range(len(A))]

    @staticmethod
    def strassen(A, B):
        n = len(A)

        if n == 1:
            return [[A[0][0] * B[0][0]]]

        k = n // 2

        A11 = [row[:k] for row in A[:k]]
        A12 = [row[k:] for row in A[:k]]
        A21 = [row[:k] for row in A[k:]]
        A22 = [row[k:] for row in A[k:]]

        B11 = [row[:k] for row in B[:k]]
        B12 = [row[k:] for row in B[k:]]
        B21 = [row[:k] for row in B[k:]]
        B22 = [row[k:] for row in B[k:]]

        P1 = MatrixMultiplication.strassen(A11, MatrixMultiplication.subtract(B12, B22))
        P2 = MatrixMultiplication.strassen(MatrixMultiplication.add(A11, A12), B22)
        P3 = MatrixMultiplication.strassen(MatrixMultiplication.add(A21, A22), B11)
        P4 = MatrixMultiplication.strassen(A22, MatrixMultiplication.subtract(B21, B11))
        P5 = MatrixMultiplication.strassen(
            MatrixMultiplication.add(A11, A22),
            MatrixMultiplication.add(B11, B22),
        )
        P6 = MatrixMultiplication.strassen(
            MatrixMultiplication.subtract(A12, A22),
            MatrixMultiplication.add(B21, B22),
        )
        P7 = MatrixMultiplication.strassen(
            MatrixMultiplication.subtract(A11, A21),
            MatrixMultiplication.add(B11, B12),
        )

        C11 = MatrixMultiplication.add(
            MatrixMultiplication.subtract(MatrixMultiplication.add(P5, P4), P2),
            P6,
        )
        C12 = MatrixMultiplication.add(P1, P2)
        C21 = MatrixMultiplication.add(P3, P4)
        C22 = MatrixMultiplication.subtract(
            MatrixMultiplication.subtract(MatrixMultiplication.add(P1, P5), P3),
            P7,
        )

        C = []

        for i in range(k):
            C.append(C11[i] + C12[i])
        for i in range(k):
            C.append(C21[i] + C22[i])

        return C
