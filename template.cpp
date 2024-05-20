#include <iostream>
using namespace std;

int main() {
  int arr[10] = {3, 4, 5, 6, 7, 8, 9, 0, 1, 2};
  int len = sizeof(arr) / sizeof(arr[0]);

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
