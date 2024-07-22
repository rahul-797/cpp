#include <iostream>
using namespace std;

int main() {
  int num;
  cin >> num;
  char ch = 'A';
  for (int i = 0; i < num; i++) {
    ch = 'A';
    for (int j = 0; j < num - i - 1; j++) {
      cout << " ";
    }
    for (int j = num; j >= num - i; j--, ch++) {
      cout << char(ch);
    }
    ch -= 2;
    for (int j = 0; j < i; j++, ch--) {
      cout << char(ch);
    }
    cout << endl;
  }
  return 0;
}
