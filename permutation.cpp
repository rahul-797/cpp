#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(string str, int index, vector<string>& answer) {
  if (index >= str.length()) {
    answer.push_back(str);
    return;
  }
  for (int i = index; i < str.length(); i++) {
    char temp = str[i];
    str[i] = str[index];
    str[index] = temp;
    solve(str, index + 1, answer);
  }
}

int main() {
  string str = "qwer";
  vector<string> answer;
  int index = 0;

  solve(str, index, answer);
  sort(answer.begin(), answer.end());

  for (string s : answer) {
    cout << s << endl;
  }
  return 0;
}
