#include <iostream>
using namespace std;

void shift(int arr[], int len, int i) {
  for (; i < len; i++) {
    arr[i] = arr[i + 1];
  }
  arr[len - 1] = 0;
}

int main() {
  int arr[10] = {1, 0, 0, 3, 0, 0, 2, 0, 9, 0};
  int len = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0, j = 0; i < len; i++, j++) {
    if (arr[i] == 0) {
      shift(arr, len, i);
      if (arr[j] == 0) i--;
    }
  }

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
