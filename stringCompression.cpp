/*
* Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters
in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be
stored in the input character array chars. Note that group lengths that are 10
or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the
array.

You must write an algorithm that uses only constant extra space.



Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be:
["a","2","b","2","c","3"] Explanation: The groups are "aa", "bb", and "ccc".
This compresses to "a2b2c3". Example 2:

Input: chars = ["a"]
Output: Return 1, and the first character of the input array should be: ["a"]
Explanation: The only group is "a", which remains uncompressed since it's a
single character. Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: Return 4, and the first 4 characters of the input array should be:
["a","b","1","2"]. Explanation: The groups are "a" and "bbbbbbbbbbbb". This
compresses to "ab12".


Constraints:

1 <= chars.length <= 2000
chars[i] is a lowercase English letter, uppercase English letter, digit, or
symbol.
  */

#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<char> s;
  s.push_back('a');
  s.push_back('0');
  s.push_back('b');
  s.push_back('b');
  s.push_back('c');
  vector<char> ch;
  vector<int> no;
  vector<string> final;

  for (int i = 0; i < s.size(); i++) {
    if (ch.size() && ch.back() == s[i]) {
      no[no.size() - 1] += 1;
      if (i == s.size() - 1 || s[i + 1] != s[i])
        final.push_back(to_string(no[no.size() - 1]));
    } else {
      ch.push_back(s[i]);
      final.push_back(string() + s[i]);
      no.push_back(1);
    }
  }
  s.clear();
  for (int i = 0; i < final.size(); i++) {
    if (!all_of(final[i].begin(), final[i].end(), ::isdigit)) {
      const char* a = final[i].c_str();
      s.push_back(*a);
    } else {
      int num = stoi(final[i]);
      if (num == 0) {
        s.push_back(num);
        continue;
      }
      while (num) {
        s.push_back('0' + (num % 10));
        num /= 10;
      }
    }
  }

  for (auto i : s) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
