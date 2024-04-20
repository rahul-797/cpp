#include <climits>
#include <iostream>
using namespace std;

int findSqrt(int n) {
  int start = 0;
  int end = 46300;
  int mid = start + (end - start) / 2;
  while (start < end) {
    if (mid * mid <= n && (mid + 1) * (mid + 1) > n) break;
    if (mid * mid > n)
      end = mid;
    else
      start = mid;
    mid = start + (end - start) / 2;
  }
  return mid;
}

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  int sqrt = findSqrt(n);
  cout << "Integral value of its square root is: " << sqrt << endl;
  return 0;
}
