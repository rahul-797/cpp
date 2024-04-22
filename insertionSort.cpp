#include <iostream>
using namespace std;

void insertionSort(int arr[], int len, int newArr[]) {
  for (int i = 0; i < len; i++) {
    int j = i - 1;
    for (; j >= 0; j--) {
      if (newArr[j] > arr[i]) {
        newArr[j + 1] = newArr[j];
        continue;
      }
      break;
    }
    j += 1;
    newArr[j] = arr[i];
  }
}

int main() {
  int arr[10] = {-1, 10, 0, 12, 11, -4, 8, -2, 9, 0};
  int len = sizeof(arr) / sizeof(arr[0]);
  int newArr[10] = {0};
  insertionSort(arr, len, newArr);
  cout << "Array: ";
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  cout << "Sort:  ";
  for (int i = 0; i < len; i++) {
    cout << newArr[i] << " ";
  }
  cout << endl;
  return 0;
}
