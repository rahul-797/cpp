#include <climits>
#include <iostream>
using namespace std;

double findSqrt(int n) {
  int start = 0;
  long long int end = INT_MAX;
  long long int mid = start + (end - start) / 2;
  while (start < end) {
    if (mid * mid <= n && (mid + 1) * (mid + 1) > n) break;
    if (mid * mid > n)
      end = mid;
    else
      start = mid;
    mid = start + (end - start) / 2;
  }

  int integral = mid;
  int i = 0;
  double decimal;
  double number;
  double answer = integral;
  int numOfDecimal = 10;
  while (numOfDecimal != 10000000) {
    decimal = 1.0 / numOfDecimal;
    number = answer + (i * decimal);
    if (number * number < n && i != 10) {
      answer = number;
      i++;
    } else {
      numOfDecimal *= 10;
      i = 0;
    }
  }
  return answer;
}

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  double sqrt = findSqrt(n);
  cout << "Value of its square root is: " << sqrt << endl;
  return 0;
}
