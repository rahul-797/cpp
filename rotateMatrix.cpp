#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n = 4;
int newPos[2];
int buffer = 0;
int startPos[2];

bool switched(unordered_map<int, int>::iterator start,
              unordered_map<int, int>::iterator end, int row, int col) {
  for (auto i = start; i != end; i++) {
    if (i->first == row && i->second == col) return true;
  }
  return false;
}

int* correctPos(int pos[]) {
  newPos[0] = pos[1];
  newPos[1] = n + 1 - pos[0];
  return &newPos[0];
}

void changePos(vector<vector<int>>& matrix, int pos[], int newPos[]) {
  buffer = matrix[newPos[0]][newPos[1]];
  matrix[newPos[0]][newPos[1]] = matrix[pos[0]][pos[1]];
}

int main() {
  vector<vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  unordered_map<int, int> hash;

  for (int row = 1; row <= n; row++) {
    for (int col = 1; col <= n; col++) {
      if (switched(hash.begin(), hash.end(), row, col)) continue;
      int pos[2] = {row, col};
      correctPos(pos);
      startPos[0] = row, startPos[1] = col;
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
