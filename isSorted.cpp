#include <iostream>
using namespace std;

int i = 0;

bool isSorted(int *arr, int size) {
  if (i + 1 < size && arr[i] > arr[i + 1]) {
    cout << "Not sorted" << endl;
    return false;
  }
  if (i == size - 1) {
    cout << "Sorted" << endl;
    return true;
  }
  i++;
  return isSorted(arr, size);
}

int main() {
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  isSorted(arr, size);
  return 0;
}
