#include <iostream>
using namespace std;

void binSearch(int arr[], int len, int num) {
  int start = 0;
  int end = len - 1;
  int index = start + (end - start) / 2;
  while (start <= end) {
    if (arr[index] == num) {
      cout << "Found " << num << " at index: " << index << endl;
      return;
    }
    if (arr[index] < num) {
      start = index + 1;
    } else {
      end = index - 1;
    }
    int index = start + (end - start) / 2;
  }
  cout << "Not found!" << endl;
}

int main() {
  int arr[19] = {0,  1,  2,  3,  4,  5,  6,  7,  8, 9,
                 10, 11, 12, 13, 14, 15, 16, 17, 18};
  int n;
  cin >> n;
  binSearch(arr, sizeof(arr) / sizeof(arr[0]), n);

  return 0;
}
