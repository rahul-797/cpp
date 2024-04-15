#include <iostream>

using namespace std;

int main() {
  int input, mask = 0, i = 0;
  cin >> input;
  int n = input;

  while (n != 0) {
    n = n >> 1;
    i++;
  }
  while (i > 0) {
    mask = (mask << 1) | 1;
    i--;
  }
  cout << ((~input) & mask) << endl;

  return 0;
}
