#include <iostream>
#include <utility>
using namespace std;

int main() {
  int arr[10] = {1, 0, 0, 3, 0, 0, 2, 0, 9, 0};
  int len = sizeof(arr) / sizeof(arr[0]);

  int index = 0;

  for (int i = 0; i < len; i++) {
    if (arr[i] != 0) {
      swap(arr[i], arr[index]);
      index++;
    }
  }

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
