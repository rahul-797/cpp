#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, i = 0, bin = 0;
  cin >> n;
  int com = 0;

  while (n != 0) {
    bin += (n & 1) * pow(10, i);
    i++;
    n = n >> 1;
  }

  for (int j = 0; j < i; j++) {
    int rem = bin % 10 ? 0 : 1;
    com += (rem * pow(10, j));
    bin /= 10;
  }
  int complement = 0;
  int len = to_string(com).length();

  for (int j = 0; j < len; j++) {
    int rem = com % 10;
    complement += round((rem * pow(2, j)));
    com /= 10;
  }

  cout << complement << endl;
  return 0;
}
