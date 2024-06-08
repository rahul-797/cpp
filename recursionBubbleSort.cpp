#include <iostream>
using namespace std;

bool sortNeeded = true;

bool bubble(int* arr, int size, bool& sortNeeded) {
  if (size == 1) return true;
  if (arr[0] > arr[1]) {
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
    sortNeeded = true;
  }
  return bubble(arr + 1, size - 1, sortNeeded);
}

int main() {
  int arr[10] = {4, 2, 5, 8, 32, 7, 0, -1, 12, 23};
  for (int i : arr) {
    cout << i << " ";
  }
  cout << endl;
  while (sortNeeded) {
    sortNeeded = false;
    bubble(arr, sizeof(arr) / sizeof(arr[0]), sortNeeded);
  }
  for (int i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
