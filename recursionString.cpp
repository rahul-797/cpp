#include <iostream>
#include <string>
using namespace std;

string rev(string str) {
  if (str.length() == 1 || str.length() == 0) return str;
  char back = str.back();
  str.pop_back();
  return back + rev(str);
}

bool checkPalindrome(string& str, int size, int i = 0) {
  if (i == size - i - 1 || i * 2 == size) return true;
  if (str[i] != str[size - i - 1]) return false;
  return checkPalindrome(str, size, ++i);
}

int main() {
  string str = "Rac#caR";
  cout << "Original: " << str << endl;
  cout << "Reversed: " << rev(str) << endl;
  cout << "Is palindrome: " << checkPalindrome(str, str.size()) << endl;
  return 0;
}
