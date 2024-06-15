#include <iostream>
#include <vector>
using namespace std;

void solve(string digits, int index, vector<vector<char>>& map, string output,
           vector<string>& answer) {
  if (index >= digits.size()) {
    answer.push_back(output);
    return;
  }
  int indexInMap = digits[index] - '0' - 2;
  for (int i = 0; i < map[indexInMap].size(); i++) {
    output.push_back(map[indexInMap][i]);
    solve(digits, index + 1, map, output, answer);
    output.pop_back();
  }
}

int main() {
  string digits = "23";
  vector<vector<char>> map = {{'a', 'b', 'c'}, {'d', 'e', 'f'},
                              {'g', 'h', 'i'}, {'j', 'k', 'l'},
                              {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                              {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
  string output;
  vector<string> answer;
  int index = 0;

  solve(digits, index, map, output, answer);

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << endl;
  }
  return 0;
}
