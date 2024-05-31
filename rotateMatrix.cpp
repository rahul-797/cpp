#include <iostream>
#include <unordered_map>
using namespace std;

int n = 4;

bool switched(unordered_map<int, int> hash, int row, int col) {
  for (auto [i, j] : hash) {
    if (i == row && j == col) return true;
  }
  // simply find the pair in hash using builtin fn. remove this method(fn)
  return false;
}

int* correctPos(int* pos) {
  int temp = pos[1];
  pos[1] = n + 1 - pos[0];
  pos[0] = temp;
  return pos;
}

void changePos(int* arr[][n]) {}

int main() {
  int matrix[4][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
  unordered_map<int, int> hash;

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (switched(hash, row, col)) continue;
    }
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
