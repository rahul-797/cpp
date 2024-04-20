#include <iostream>
using namespace std;

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void rotateArray(int arr[], int rot[], int i, int len) {
  int j = 0;

  while (j < len) {
    if (i < len)
      rot[j] = arr[i];
    else {
      i %= len;
      rot[j] = arr[i];
    }
    i++, j++;
  }
}

int findPivot(int rot[], int len) {
  int start = 0;
  int end = len - 1;
  int mid = start + (end - start) / 2;
  while (start < end) {
    if (rot[mid] > rot[0]) start = mid + 1;

    if (rot[mid] < rot[0]) end = mid;

    mid = start + (end - start) / 2;
  }
  return rot[mid];
}

int main() {
  int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int len = sizeof(arr) / sizeof(arr[0]);
  int rot[15];
  rotateArray(arr, rot, 7, len);
  cout << " Array: ";
  printArray(arr, len);
  cout << "Rotate: ";
  printArray(rot, len);
  int pivot = findPivot(rot, len);
  cout << "Pivot: " << pivot << endl;
  return 0;
}
