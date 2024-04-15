#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n, rev = 0, i = 0;
  cin >> n;

  int ni = 2147483647;
  cout << ni << endl;
  while (n != 0) {
    rev = (n % 10) + (rev * 10);
    i--;
    n /= 10;
  }
  cout << rev << endl;
  return 0;
}
