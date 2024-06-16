/// Rat Maze problem

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to
// reach the destination at (N - 1, N - 1). Find all possible paths that the rat
// can take to reach from source to destination. The directions in which the rat
// can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell
// in the matrix represents that it is blocked and rat cannot move to it while
// value 1 at a cell in the matrix represents that rat can be travel through it.
// In a path, no cell can be visited more than one time.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(vector<vector<int>>& vec, vector<vector<int>>& visited,
           string output, int r, int c, vector<string>& answer) {
  if (r >= vec.size() - 1 && c >= vec[0].size() - 1) {
    answer.push_back(output);
    return;
  }

  visited[r][c] = 1;

  if (r + 1 < vec.size() && vec[r + 1][c] == 1 && visited[r + 1][c] == 0) {
    output.push_back('D');
    solve(vec, visited, output, r + 1, c, answer);
    output.pop_back();
  }
  if (c + 1 < vec[0].size() && vec[r][c + 1] == 1 && visited[r][c + 1] == 0) {
    output.push_back('R');
    solve(vec, visited, output, r, c + 1, answer);
    output.pop_back();
  }
  if (c > 0 && vec[r][c - 1] == 1 && visited[r][c - 1] == 0) {
    output.push_back('L');
    solve(vec, visited, output, r, c - 1, answer);
    output.pop_back();
  }
  if (r > 0 && vec[r - 1][c] == 1 && visited[r - 1][c] == 0) {
    output.push_back('U');
    solve(vec, visited, output, r - 1, c, answer);
    output.pop_back();
  }
  visited[r][c] = 0;
}

int main() {
  vector<vector<int>> vec = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  string output = "";
  vector<string> answer = {};
  int r = 0, c = 0;

  vector<vector<int>> visited(vec.size(), vector<int>(vec.size(), 0));
  visited[0][0] = 1;

  solve(vec, visited, output, r, c, answer);

  cout << "Matrix:" << endl;
  for (auto i : vec) {
    cout << "\t";
    for (auto j : i) {
      cout << j << " ";
    }
    cout << endl;
  }

  cout << "Valid moves are:" << endl;
  for (string s : answer) {
    cout << "\t" << s << endl;
  }
  return 0;
}
