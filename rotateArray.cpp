#include <iostream>
using namespace std;

int main() {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len = sizeof(arr) / sizeof(arr[0]);
  int k;
  int arr2[len];

  cout << "Enter number to shift array by: ";
  cin >> k;

  if (k > len) {
    k %= len;
  }

  for (int i = 0; i < len - k; i++) {
    arr2[i + k] = arr[i];
  }

  int index = 0;
  for (int i = len - k; index < k; i++, index++) {
    arr2[index] = arr[i];
  }

  for (auto i : arr2) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
