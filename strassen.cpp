#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> add(const vector<vector<int>>& A,
                        const vector<vector<int>>& B) {
  int n = A.size();
  vector<vector<int>> C(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) C[i][j] = A[i][j] + B[i][j];
  return C;
}

// Function to subtract two matrices
vector<vector<int>> subtract(const vector<vector<int>>& A,
                             const vector<vector<int>>& B) {
  int n = A.size();
  vector<vector<int>> C(n, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) C[i][j] = A[i][j] - B[i][j];
  return C;
}

// Strassen's algorithm for matrix multiplication
vector<vector<int>> strassen(const vector<vector<int>>& A,
                             const vector<vector<int>>& B) {
  int n = A.size();

  // Base case for recursion
  if (n == 1) {
    return {{A[0][0] * B[0][0]}};
  }

  // Dividing the matrices into quarters
  int k = n / 2;

  // Create submatrices
  vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)),
      A21(k, vector<int>(k)), A22(k, vector<int>(k)), B11(k, vector<int>(k)),
      B12(k, vector<int>(k)), B21(k, vector<int>(k)), B22(k, vector<int>(k));

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

  // Calculating the seven products
  auto P1 = strassen(add(A11, A22), add(B11, B22));
  auto P2 = strassen(add(A21, A22), B11);
  auto P3 = strassen(A11, subtract(B12, B22));
  auto P4 = strassen(A22, subtract(B21, B11));
  auto P5 = strassen(add(A11, A12), B22);
  auto P6 = strassen(subtract(A21, A11), add(B11, B12));
  auto P7 = strassen(subtract(A12, A22), add(B21, B22));

  // Combining the results into a single matrix
  vector<vector<int>> C(n, vector<int>(n));

  // C11
  auto C11 = add(subtract(add(P1, P4), P5), P7);

  // C12
  auto C12 = add(P3, P5);

  // C21
  auto C21 = add(P2, P4);

  // C22
  auto C22 = add(subtract(add(P1, P3), P2), P6);

  // Fill the result matrix
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

// Utility function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (const auto& elem : row) {
      cout << elem << " ";
    }
    cout << endl;
  }
}

// Main function to demonstrate Strassen's algorithm
int main() {
  int n;

  cout << "Enter the size of the matrices (must be a power of 2): ";
  cin >> n;

  // Initialize matrices
  vector<vector<int>> A(n, vector<int>(n));
  vector<vector<int>> B(n, vector<int>(n));

  cout << "Enter elements of matrix A:" << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> A[i][j];

  cout << "Enter elements of matrix B:" << endl;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> B[i][j];

  // Multiply matrices using Strassen's algorithm
  vector<vector<int>> result = strassen(A, B);

  cout << "Resultant Matrix:" << endl;
  printMatrix(result);

  return 0;
}
