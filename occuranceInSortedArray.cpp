#include <iostream>
using namespace std;

int firstOccurance(int arr[], int len, int n) {
  int index = -1;
  int start = 0;
  int end = len - 1;
  int mid = start + (end - start) / 2;
  while (start <= end) {
    if (arr[mid] == n) {
      index = mid;
      end = mid - 1;
    } else if (arr[mid] < n) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return index;
}

int lastOccurance(int arr[], int len, int n) {
  int index = -1;
  int start = 0;
  int end = len - 1;
  int mid = start + (end - start) / 2;
  while (start <= end) {
    if (arr[mid] == n) {
      index = mid;
      start = mid + 1;
    } else if (arr[mid] > n) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return index;
}

int main() {
  int arr[20] = {1, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5, 6, 7, 7, 8, 9, 9, 9, 9, 10};
  int len = sizeof(arr) / sizeof(arr[0]);
  int n;
  cin >> n;

  cout << "Array: ";
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  int first = firstOccurance(arr, len, n);
  cout << "First occurance of " << n << " is at index: " << first << endl;
  int last = lastOccurance(arr, len, n);
  cout << "last occurance of " << n << " is at index: " << last << endl;
  return 0;
}
