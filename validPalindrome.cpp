#include <iostream>
#include <string>
using namespace std;

bool is(string s) {
  for (int i = 0; i < s.length(); i++) {
    if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
      s[i] = tolower(s[i]);
    } else if ((s[i] >= '0' && s[i] <= '9')) {
      continue;
    } else {
      s.erase(i--, 1);
    }
  }

  int start = 0, end = s.length() - 1;
  while (start <= end) {
    if (s[start++] == s[end--]) {
      continue;
    }
    return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  cout << "Is valid palindrome: " << is(s) << endl;
  return 0;
}
