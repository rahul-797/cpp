#include <iostream>
using namespace std;

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int len = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i <= (len - 1) / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[len - i - 1];
    arr[len - i - 1] = temp;
  }

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
