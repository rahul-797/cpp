#include <iostream>
using namespace std;

int main() {
  int matrix[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  int arr[16] = {0};
  int rowStart = 0;
  int rowEnd = 3;
  int colStart = 0;
  int colEnd = 3;

  int count = 0;
  int total = 16;

  while (count < total) {
    for (int i = colStart; count < total && i <= colEnd; i++) {
      arr[count] = matrix[rowStart][i];
      count++;
    }
    rowStart++;
    for (int i = rowStart; count < total && i <= rowEnd; i++) {
      arr[count] = matrix[i][colEnd];
      count++;
    }
    colEnd--;
    for (int i = colEnd; count < total && i >= colStart; i--) {
      arr[count] = matrix[rowEnd][i];
      count++;
    }
    rowEnd--;
    for (int i = rowEnd; count < total && i >= rowStart; i--) {
      arr[count] = matrix[i][colStart];
      count++;
    }
    colStart++;
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
