#include <iostream>
using namespace std;

void arrange(int arr[], int len) {
  int i = 0;
  int j = 1;

  while (i < len) {
    if (arr[i] == 1) {
      j = i + 1;
      while (j > i && j < len) {
        if (arr[j] == 0) {
          swap(arr[i], arr[j]);
          arrange(arr, len);
        }
        j++;
      }
    }
    if (arr[i] == 2) {
      int length = len;
      while (length > i) {
        if (arr[length] == 1 || arr[length] == 0) {
          swap(arr[i], arr[length]);
        }
        length--;
      }
    }
    i++;
  }
}

int main() {
  int arr[15] = {2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
  int len = sizeof(arr) / sizeof(arr[0]);
  arrange(arr, len);

  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
