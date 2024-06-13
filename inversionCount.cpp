#include <iostream>
using namespace std;

int mergeArr(int *arr, int s, int e, int mid) {
  int inv = 0;
  int len1 = mid - s + 1;
  int len2 = e - mid;
  int *arr1 = new int[len1];
  int *arr2 = new int[len2];

  int k = s;
  for (int i = 0; i < len1; i++) {
    arr1[i] = arr[k++];
  }
  k = mid + 1;
  for (int j = 0; j < len2; j++) {
    arr2[j] = arr[k++];
  }

  int i = 0, j = 0;
  int index = s;
  while (i < len1 && j < len2) {
    if (arr1[i] <= arr2[j]) {
      arr[index++] = arr1[i++];
    } else {
      arr[index++] = arr2[j++];
      inv += len1 - i;
    }
  }
  while (i < len1) {
    arr[index++] = arr1[i++];
  }
  while (j < len2) {
    arr[index++] = arr2[j++];
  }

  delete[] arr1;
  delete[] arr2;
  return inv;
}

int mergeSort(int *arr, int s, int e) {
  if (s >= e) return 0;
  int mid = s + (e - s) / 2;
  mergeSort(arr, s, mid);
  mergeSort(arr, mid + 1, e);
  return mergeArr(arr, s, e, mid);
}

int main() {
  int arr[10] = {4, 3, 7, 1, 9, 3, 6, 0, 5, -1};

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  int inv = mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
  cout << "Inversion: " << inv << endl;
  return 0;
}
