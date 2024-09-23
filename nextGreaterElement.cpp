#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  stack<int> s;
  vector<int> vec = {9, 3, 1, 9, 3, 5, 2, 0, 1, 7};
  for (int i = vec.size() - 1; i >= 0; i--) {
    if (s.empty()) {
      cout << vec[i] << " -> -1" << endl;
      s.push(vec[i]);
    } else {
      if (vec[i] < s.top()) {
        cout << vec[i] << " -> " << s.top() << endl;
        s.push(vec[i]);
      } else {
        while (!s.empty() && vec[i] > s.top()) s.pop();
        if (!s.empty())
          cout << vec[i] << " -> " << s.top() << endl;
        else
          cout << vec[i] << " -> -1" << endl;
        s.push(vec[i]);
      }
    }
  }
  cout << endl;
  return 0;
}
