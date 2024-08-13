#include <climits>
#include <iostream>
using namespace std;

int secLargest(int* arr, int len) {
  int max = INT_MIN;
  int sec = INT_MIN;
  for (int i = 0; i < len; i++) {
    if (arr[i] > max) {
      max = arr[i];
      continue;
    }
    if (arr[i] > sec) sec = arr[i];
  }
  return sec;
}

int main() {
  int arr[10] = {3, 6, 1, 8, 10, 7, 2, 9, 8, 4};
  int secondLargest = secLargest(arr, 10);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Second largest is: " << secondLargest << endl;
  return 0;
}
