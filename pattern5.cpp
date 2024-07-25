#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  stack<string> stack;
  int num = n;
  for (int i = 0; i < n; i++) {
    num = n;
    bool dec = true;
    bool inc = false;
    string str = "";
    for (int j = 0; j < 2 * n - 1; j++) {
      if (i != 0 && j != 0 && dec) {
        num--;
        if (num + i == n) dec = false;
      }
      if ((2 * n - 1) == i + j) inc = true;
      if (!dec && inc) num++;
      str = str + to_string(num);
      cout << num;
    }
    stack.push(str);
    cout << "\n";
  }
  stack.pop();

  while (!stack.empty()) {
    cout << stack.top() << endl;
    stack.pop();
  }
  return 0;
}
