#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<char, int> hash;
  string s1 = "ab";
  string s2 = "eidboaoo";
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
  while (end < s2.length()) {
    map<char, int> checkMap;
    for (int i = index, j = end; i <= j; i++) {
      if (checkMap.count(s2[i]) == 0) {
        checkMap[s2[i]] = 1;
      } else {
        checkMap[s2[i]] += 1;
      }
    }
    if (hash == checkMap) {
      found = true;
      break;
    }
    index++, end++;
  }
  found ? cout << "Found" << endl : cout << "Not found" << endl;
  return 0;
}
