#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
using namespace std;

void selectionSort(int arr[], int len) {
  int index = 0;
  int minIndex = 0;
  while (index < len) {
    for (int i = index; i < len; i++) {
      if (arr[i] < arr[minIndex]) {
        minIndex = i;
      }
    }
    swap(arr[index], arr[minIndex]);
    index++;
  }
}

int main() {
  int arr[10] = {2, 5, 7, 2, 1, 4, 8, 0, 9, 6};
  int len = sizeof(arr) / sizeof(arr[0]);
  selectionSort(arr, len);
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
