#include <iostream>
using namespace std;

int power(int base, int pow) {
  if (pow == 0) return 1;
  if (pow == 1) return base;
  int ans;
  ans = power(base, pow / 2);
  if (pow & 1) {
    return base * ans * ans;
  } else {
    return ans * ans;
  }
}

int main() {
  int base, pow;
  cout << "Enter base and power: ";
  cin >> base >> pow;
  cout << base << "^" << pow << ": " << power(base, pow) << endl;
  return 0;
}
