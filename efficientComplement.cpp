#include <iostream>

using namespace std;

int main() {
  int input, mask = 0;
  cin >> input;
  int n = input;

  while (n != 0) {
    mask = (mask << 1) | 1;
    n = n >> 1;
  }

  cout << ((~input) & mask) << endl;

  return 0;
}
