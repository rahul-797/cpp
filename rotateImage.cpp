#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int* getNewPos(vector<vector<int>>& arr, int* pos) {
  int temp = pos[0];
  pos[0] = pos[1];
  pos[1] = arr.size() + 1 - temp;
  return &pos[0];
}
int main() {
  vector<vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  int rows = matrix.size();
  int cols = matrix[0].size();
  int arr[rows][cols];
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      int pos[2] = {row + 1, col + 1};
      int* newPos = getNewPos(matrix, pos);
      arr[newPos[0] - 1][newPos[1] - 1] = matrix[row][col];
    }
  }
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      matrix[row][col] = arr[row][col];
    }
  }
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++) {
      cout << matrix[row][col] << " ";
    }
    cout << endl;
  }
  return 0;
}
