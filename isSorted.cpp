#include <iostream>
using namespace std;

int sum(int *arr, int size) {
  if (size == 0) return 0;
  return arr[0] + sum(arr + 1, size - 1);
}

bool isSorted(int *arr, int size) {
  if (size == 0 || size == 1) {
    cout << "Sorted" << endl;
    return true;
  }
  if (arr[0] > arr[1]) {
    cout << "Not sorted" << endl;
    return false;
  }
  return isSorted(arr + 1, size - 1);
}

int main() {
  int arr[6] = {1, 2, 3, 4, 5, 4};
  int size = sizeof(arr) / sizeof(arr[0]);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  isSorted(arr, size);
  cout << "Sum of elements is: " << sum(arr, size) << endl;
  return 0;
}
