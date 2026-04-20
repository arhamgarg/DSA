public class StrassenMatrixMultiplication {
  public static int[][] multiply(int[][] A, int[][] B) {
    int n = A.length;

    if (n == 1) {
      return new int[][] {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;

    int[][] A11 = new int[k][k], A12 = new int[k][k];
    int[][] A21 = new int[k][k], A22 = new int[k][k];

    int[][] B11 = new int[k][k], B12 = new int[k][k];
    int[][] B21 = new int[k][k], B22 = new int[k][k];

    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        A11[i][j] = A[i][j];
        A12[i][j] = A[i][j + k];
        A21[i][j] = A[i + k][j];
        A22[i][j] = A[i + k][j + k];

        B11[i][j] = B[i][j];
        B12[i][j] = B[i][j + k];
        B21[i][j] = B[i + k][j];
        B22[i][j] = B[i + k][j + k];
      }
    }

    int[][] P1 = multiply(A11, subtract(B12, B22));
    int[][] P2 = multiply(add(A11, A12), B22);
    int[][] P3 = multiply(add(A21, A22), B11);
    int[][] P4 = multiply(A22, subtract(B21, B11));
    int[][] P5 = multiply(add(A11, A22), add(B11, B22));
    int[][] P6 = multiply(subtract(A12, A22), add(B21, B22));
    int[][] P7 = multiply(subtract(A11, A21), add(B11, B12));

    int[][] C11 = add(subtract(add(P5, P4), P2), P6);
    int[][] C12 = add(P1, P2);
    int[][] C21 = add(P3, P4);
    int[][] C22 = subtract(subtract(add(P1, P5), P3), P7);

    int[][] C = new int[n][n];

    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        C[i][j] = C11[i][j];
        C[i][j + k] = C12[i][j];
        C[i + k][j] = C21[i][j];
        C[i + k][j + k] = C22[i][j];
      }
    }

    return C;
  }

  private static int[][] add(int[][] A, int[][] B) {
    int n = A.length;
    int[][] C = new int[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        C[i][j] = A[i][j] + B[i][j];
      }
    }

    return C;
  }

  private static int[][] subtract(int[][] A, int[][] B) {
    int n = A.length;
    int[][] C = new int[n][n];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        C[i][j] = A[i][j] - B[i][j];
      }
    }

    return C;
  }
}
