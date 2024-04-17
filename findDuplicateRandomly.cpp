#include <cstdlib>
#include <iostream>
using namespace std;

int findDuplicate(int arr[], int len) {
  int n = (rand() % len);
  int nn = (rand() % len);
  cout << n << " " << nn << endl;
  if ((arr[n] ^ arr[nn]) == 0 && n != nn) {
    return arr[n];
  } else {
    return findDuplicate(arr, len);
  }
}

int main() {
  int arr[8] = {5, 2, 9, 3, 7, 5, 4, 1};
  int len = sizeof(arr) / sizeof(arr[0]);
  cout << findDuplicate(arr, len) << endl;
  return 0;
}
