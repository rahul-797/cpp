#include <iostream>
using namespace std;

int main() {
  string s = "aaaaaaaa";
  bool change = true;

  while (s.length() > 1 && change) {
    change = false;
    for (int i = 0; i < s.length(); i++) {
      cout << i << "  " << s.length() << endl;
      if (s.length() > 1 && s[i] == s[i + 1]) {
        s.erase(i, 2);
        change = true;
      }
    }
  }
  cout << s << endl;
  return 0;
}
