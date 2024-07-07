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

// a = no. of {
// b = no. of }
// count = (a+1)/2 + (b+1)/2
int reversalCost(stack<char>& s, string str) {
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (s.empty()) {
      s.push(str[i]);
      count++;
      continue;
    }
    if (s.top() == '{' && str[i] == '}') {
      s.pop();
      count--;
      continue;
    }
    s.push(str[i]);
    count++;
  }
  if (count & 1) return -1;
  return count / 2;
}

int main() {
  string str = "}}}}}{";
  stack<char> s;

  int cost = reversalCost(s, str);
  cout << "The cost is: " << cost << endl;
  print(s);
  cout << endl;
  return 0;
}
