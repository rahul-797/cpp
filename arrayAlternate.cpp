#include <iostream>
#include <utility>
using namespace std;

void alternate(int arr[], int len) {
  int i = 0;
  while (i < len) {
    if (i <= len - 2) swap(arr[i], arr[i + 1]);
    i += 2;
  }
}

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  alternate(arr, sizeof(arr) / sizeof(int));
  cout << arr[0] << endl;
  cout << arr[1] << endl;
  cout << arr[2] << endl;
  cout << arr[3] << endl;
  cout << arr[4] << endl;

  return 0;
}
