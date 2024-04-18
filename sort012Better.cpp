#include <iostream>
#include <utility>
using namespace std;

void arrange(int arr[], int len) {
  int pivot = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] == 0) {
      swap(arr[i], arr[pivot]);
      pivot++;
    }
  }
  for (int i = 0; i < len; i++) {
    if (arr[i] == 1) {
      swap(arr[i], arr[pivot]);
      pivot++;
    }
  }
}

int main() {
  int arr[15] = {2, 1, 1, 0, 2, 0, 1, 0, 2, 2, 0, 1, 1, 2, 0};
  int len = sizeof(arr) / sizeof(arr[0]);
  arrange(arr, len);

  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
