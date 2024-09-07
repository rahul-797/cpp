#include <cctype>
#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int pre(char op) {
  if (op == '$') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}

int main() {
  stack<char> s;
  char str[30];
  fgets(str, 30, stdin);

  int i = 0;
  while (str[i] != '\0') {
    if (isdigit(str[i]))
      cout << str[i];
    else if (str[i] == '(') {
      s.push(str[i]);
    } else if (str[i] == ')') {
      while (!s.empty() && s.top() != '(') {
        cout << s.top();
        s.pop();
      }
      s.pop();
    } else {
      while (!s.empty() && pre(str[i]) <= pre(s.top())) {
        cout << s.top();
        s.pop();
      }
      s.push(str[i]);
    }
    i++;
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
  return 0;
}
