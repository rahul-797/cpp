#include <iostream>
#include <utility>
using namespace std;

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  int len = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i <= (len - 1) / 2; i++) {
    swap(arr[i], arr[len - 1 - i]);
  }

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
