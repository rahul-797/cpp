#include <iostream>
using namespace std;

void peak(int arr[], int len) {
  int peak = 0;
  int start = 0;
  int end = len - 1;
  int mid = start + (end - start) / 2;
  while (start <= end) {
    if (arr[mid] < arr[mid + 1]) {
      start = mid + 1;
    }
    if (arr[mid] > arr[mid + 1]) {
      end = mid - 1;
    }
    if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
      peak = arr[mid];
      break;
    }
    mid = start + (end - start) / 2;
  }
  cout << peak << endl;
}

int main() {
  int arr[7] = {4, 6, 9, 10, 6, 3, 2};
  int len = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  peak(arr, len);
  return 0;
}
