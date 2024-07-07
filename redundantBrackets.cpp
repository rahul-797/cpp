#include <iostream>
#include <stack>
using namespace std;

void print(stack<char>& s) {
  if (s.empty()) return;
  char last = s.top();
  s.pop();
  print(s);
  s.push(last);
  cout << s.top();
}

void hasRedundantBracket(stack<char>& s, bool* flag, int count = 0) {
  if (count == 2) {
    *flag = true;
    return;
  }
  if (s.empty()) {
    return;
  }
  char removed = s.top();
  s.pop();
  if (s.empty()) {
    return;
  }
  char top = s.top();
  if (top == removed && (top == ')' || top == '(')) {
    count++;
  }
  hasRedundantBracket(s, flag, count);
  s.push(top);
}

int main() {
  stack<char> s;
  bool* flag = new bool(false);
  s.push('(');
  s.push('b');
  s.push('+');
  s.push('(');
  s.push('b');
  s.push('+');
  s.push('a');
  s.push(')');
  s.push(')');

  print(s);
  cout << endl;
  hasRedundantBracket(s, flag, 0);
  cout << "Has redundant brackets: ";
  (*flag) ? cout << "true" : cout << "false";
  cout << endl;
  return 0;
}
