#include <algorithm>
#include <iostream>
using namespace std;

int totalOccurance(int arr[], int len, int n) {
  int index = -1;
  int count = 0;
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
  while (true) {
    if (arr[index] == n) {
      count++;
      index++;
      continue;
    }
    break;
  }
  return count;
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

  int total = totalOccurance(arr, len, n);
  cout << "Total occurance of " << n << " is: " << total << endl;
  return 0;
}
