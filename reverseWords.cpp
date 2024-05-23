#include <iostream>
#include <string>
using namespace std;

int main() {
  string str = "I am  rahul";
  string reversed;
  string word;
  for (int i = 0; i <= str.length(); i++) {
    if (i != str.length() && str.at(i) != ' ') {
      word.push_back(str.at(i));
    } else {
      for (int j = word.length() - 1; j >= 0; j--) {
        reversed.push_back(word[j]);
      }
      if (reversed.back() != ' ') reversed.push_back(' ');
      word.clear();
    }
  }
  cout << reversed << endl;

  return 0;
}
