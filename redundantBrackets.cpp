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

void hasRedundantBracket(stack<char>& s) {
  if (s.empty()) {
    cout << "No redundant brackets" << endl;
    return;
  }
  char removed = s.top();
  s.pop();
  if (s.empty()) {
    cout << "No redundant brackets" << endl;
    return;
  }
  char top = s.top();
  if (top == removed && top == ')') {
    cout << "Has redundant brackets" << endl;
    return;
  }
  hasRedundantBracket(s);
  s.push(top);
}

int main() {
  stack<char> s;
  s.push('(');
  s.push('(');
  s.push('a');
  s.push(')');
  s.push(')');

  print(s);
  cout << endl;
  hasRedundantBracket(s);
  return 0;
}
