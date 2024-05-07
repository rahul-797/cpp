#include <iostream>
using namespace std;

int main() {
  int arr1[4] = {1, 3, 5, 7};
  int arr2[3] = {1, 2, 6};

  int len1 = sizeof(arr1) / sizeof(arr1[0]);
  int len2 = sizeof(arr2) / sizeof(arr2[0]);

  int i = 0, j = 0, k = 0;
  int arr[len1 + len2];

  while (j <= len1 - 1 && k <= len2 - 1) {
    if (arr1[j] < arr2[k]) {
      arr[i++] = arr1[j++];
    } else {
      arr[i++] = arr2[k++];
    }
  }

  while (j <= len1 - 1) {
    arr[i++] = arr1[j++];
  }

  while (k <= len2 - 1) {
    arr[i++] = arr2[k++];
  }

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
