#include <iostream>
using namespace std;

void shift(int arr[], int len, int i) {
  int end = len - 1;
  while (end > i) {
    arr[end] = arr[end - 1];
    end--;
  }
}

int main() {
  int arr1[1] = {0};
  int arr2[1] = {1};

  int len1 = sizeof(arr1) / sizeof(arr1[0]);
  int len2 = sizeof(arr2) / sizeof(arr2[0]);

  int i = 0, j = 0;
  while (j < len2) {
    if (i < len1 && arr1[i] < arr2[j]) {
      i++;
      continue;
    } else {
      shift(arr1, len1, i);
      arr1[i] = arr2[j++];
    }
  }
  i = len1 - 1, j = len2 - 1;
  while (arr1[i] == 0 && i >= 0) {
    arr1[i--] = arr2[j--];
  }

  for (auto i : arr1) {
    cout << i << " ";
  }
  cout << "\n";

  return 0;
}
