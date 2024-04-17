#include <iostream>
using namespace std;

void arrange(int arr[], int len) {
  int i = 0;
  int j = 0;

  while (i < len) {
    if (arr[i] == 1) {
      int length = len;
      while (length > i) {
        if (arr[length] == 0) {
          swap(arr[i], arr[length]);
        }
        length--;
      }
    }
    i++;
  }
}

int main() {
  int arr[10] = {1, 1, 0, 0, 1, 1, 1, 1, 0, 0};
  int len = sizeof(arr) / sizeof(arr[0]);
  arrange(arr, len);

  for (int i = 0; i < 10; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
