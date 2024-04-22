#include <iostream>
#include <utility>
using namespace std;

void bubbleSort(int arr[], int len) {
  int swaps = len;
  int j = 0;
  while (swaps) {
    swaps = 0;
    for (int i = 0; i < len - j; i++) {
      if (arr[i] > arr[i + 1] && i < len - 1) {
        swap(arr[i], arr[i + 1]);
        swaps++;
      }
    }
    j++;
  }
}

int main() {
  int arr[10] = {2, 5, 7, 2, 1, 4, 8, 0, 9, 6};
  int len = sizeof(arr) / sizeof(arr[0]);
  bubbleSort(arr, len);
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}
