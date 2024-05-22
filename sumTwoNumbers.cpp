#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i];
  }
  cout << endl;
}

int main() {
  int arr1[4] = {9, 3, 3, 2};
  int arr2[3] = {7, 4, 1};
  int len1 = sizeof(arr1) / sizeof(arr1[0]);
  int len2 = sizeof(arr2) / sizeof(arr2[0]);

  int j = len1 - 1, k = len2 - 1;
  vector<int> vec;
  int carry = 0;

  while (j >= 0 && k >= 0) {
    int sum = arr1[j] + arr2[k] + carry;
    vec.push_back(sum % 10);
    carry = sum / 10;
    j--, k--;
  }

  while (j >= 0) {
    int sum = arr1[j] + carry;
    vec.push_back(sum % 10);
    carry = sum / 10;
    j--;
  }

  while (k >= 0) {
    int sum = arr2[k] + carry;
    vec.push_back(sum % 10);
    carry = sum / 10;
    k--;
  }

  if (carry) vec.push_back(1);

  printArr(arr1, len1);
  printArr(arr2, len2);
  reverse(vec.begin(), vec.end());
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i];
  }
  cout << endl;
  return 0;
}
