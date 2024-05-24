#include <iostream>
using namespace std;

int main() {
  string s = "abccbada";
  /*
   * Using stack
   *
    stack<char> pile;
    for (int i = 0; i < s.length(); i++) {
      if (pile.empty() || pile.top() != s[i]) {
        pile.push(s[i]);
      } else {
        pile.pop();
      }
    }
    string ss = "";
    while (!pile.empty()) {
      string ch = "";
      ch += pile.top();
      ss.insert(0, ch);
      pile.pop();
    }
    cout << ss << endl;
    */

  // using string as stack!
  string ss;
  for (auto ch : s) {
    if (ss.size() && ss.back() == ch)
      ss.pop_back();
    else
      ss.push_back(ch);
  }
  cout << ss << endl;

  return 0;
}
