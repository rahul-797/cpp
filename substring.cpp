#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string s, int index, string output, vector<string>& answer) {
  if (index >= s.length()) {
    answer.push_back(output);
    return;
  }
  solve(s, index + 1, output, answer);

  output.push_back(s[index]);
  solve(s, index + 1, output, answer);
}

int main() {
  string s = "abcd";
  string output;
  vector<string> answer;
  int index = 0;

  solve(s, index, output, answer);

  cout << "Array: {";
  for (int i = 0; i < s.length(); i++) {
    cout << s[i];
    if (i != s.length() - 1) cout << ",";
  }
  cout << "}" << endl << "Total elements: " << answer.size() << endl;
  for (int i = 0; i < answer.size(); i++) {
    cout << "{";
    for (int j = 0; j < answer[i].size(); j++) {
      cout << answer[i][j];
      if (j != answer[i].size() - 1) cout << ",";
    }
    cout << "}" << endl;
  }
  return 0;
}
