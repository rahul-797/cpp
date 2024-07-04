#include <iostream>
#include <stack>
using namespace std;

void print(stack<char> s) {
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main() {
  string str = "[[({})[";

  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    if (s.empty()) {
      s.push(str[i]);
      continue;
    } else if (str[i] == '}' && s.top() == '{') {
      s.pop();
      continue;
    } else if (str[i] == ']' && s.top() == '[') {
      s.pop();
      continue;
    } else if (str[i] == ')' && s.top() == '(') {
      s.pop();
      continue;
    }
    s.push(str[i]);
  }
  print(s);
  cout << s.empty() << endl;
  return 0;
}
