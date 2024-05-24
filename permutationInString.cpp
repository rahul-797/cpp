#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<char, int> hash;
  string s1 = "ab";
  string s2 = "eidtbaoo";
  bool found = false;
  for (int i = 0; i < s1.length(); i++) {
    if (hash.count(s1[i]) == 0) {
      hash[s1[i]] = 1;
    } else {
      hash[s1[i]] += 1;
    }
  }
  int index = 0;
  int end = s1.length() - 1;
  map<char, int> checkMap;
  cout << s2 << endl;
  while (end < s2.length()) {
    if (index == 0) {
      for (int i = index, j = end; i <= j; i++) {
        if (checkMap.count(s2[i]) == 0) {
          checkMap[s2[i]] = 1;
        } else {
          checkMap[s2[i]] += 1;
        }
      }
    } else {
      if (checkMap[s2[index - 1]] == 1) {
        checkMap.erase(s2[index - 1]);
      } else {
        checkMap[s2[index - 1]] -= 1;
      }
      if (checkMap.count(s2[end]) == 0) {
        checkMap[s2[end]] = 1;
      } else {
        checkMap[s2[end]] += 1;
      }
    }
    if (hash == checkMap) {
      found = true;
      break;
    }
    for (auto [a, b] : checkMap) {
      cout << a << " " << b << " ";
    }
    cout << endl;
    index++, end++;
  }
  found ? cout << "Found" << endl : cout << "Not found" << endl;
  return 0;
}
