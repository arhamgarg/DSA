#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// given 2 matrices A and B: return A X B
Matrix multiply(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      for (int j = 0; j < n; j++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return C;
}

// given 2 matrices A and B: return A + B
Matrix add(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
  return C;
}

// given 2 matrices A and B: return A - B
Matrix subtract(const Matrix &A, const Matrix &B) {
  int n = A.size();
  Matrix C(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      C[i][j] = A[i][j] - B[i][j];
    }
  }
  return C;
}

// Strassen multiplication
Matrix strassen(const Matrix &A, const Matrix &B) {
  int n = A.size();

  if (n <= 2) {
    return multiply(A, B);
  }

  int k = n / 2;

  // divide matrices into 4 parts each
  Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k));
  Matrix A21(k, vector<int>(k)), A22(k, vector<int>(k));

  Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k));
  Matrix B21(k, vector<int>(k)), B22(k, vector<int>(k));

  // fill sub matrices
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

  // compute the 7 products (core idea of Strassen)
  Matrix P1 = strassen(A11, subtract(B12, B22));
  Matrix P2 = strassen(add(A11, A12), B22);
  Matrix P3 = strassen(add(A21, A22), B11);
  Matrix P4 = strassen(A22, subtract(B21, B11));
  Matrix P5 = strassen(add(A11, A22), add(B11, B22));
  Matrix P6 = strassen(subtract(A12, A22), add(B21, B22));
  Matrix P7 = strassen(subtract(A11, A21), add(B11, B12));

  // merge partial results into final quadrants
  Matrix C11 = add(subtract(add(P5, P4), P2), P6);
  Matrix C12 = add(P1, P2);
  Matrix C21 = add(P3, P4);
  Matrix C22 = subtract(subtract(add(P1, P5), P3), P7);

  Matrix C(n, vector<int>(n));

  // place each quadrant into result matrix
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

// print matrix
void printMatrix(const Matrix &m) {
  for (const auto &row : m) {
    for (int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

int main() {
  // sample 4 x 4 matrix input
  Matrix A = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  Matrix B = {
      {17, 18, 19, 20}, {21, 22, 23, 24}, {25, 26, 27, 28}, {29, 30, 31, 32}};

  cout << "Matrix A:\n";
  printMatrix(A);

  cout << "Matrix B:\n";
  printMatrix(B);

  // perform strassen multiplication
  Matrix C = strassen(A, B);

  cout << "Result Matrix:\n";
  printMatrix(C);

  return 0;
}
