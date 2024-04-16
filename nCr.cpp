#include <iostream>

using namespace std;

int factorial(int n) {
  if (n < 2)
    return 1;
  else
    return n * factorial(n - 1);
}

int ncr(int n, int r) { return factorial(n) / factorial(r) * factorial(n - r); }

int main() {
  int n, r;
  cin >> n >> r;
  if (n < r) {
    cout << "n can not be less than r" << endl;
    exit(0);
  }
  cout << ncr(n, r) << endl;
  return 0;
}
