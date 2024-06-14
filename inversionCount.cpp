#include <iostream>
#include <vector>
using namespace std;

int mergeArr(int *arr, int s, int e, int mid) {
  int inv = 0;
  vector<int> vec;
  int left = s;
  int right = mid + 1;

  int index = s;
  while (left <= mid && right <= e) {
    if (arr[left] <= arr[right]) {
      vec.push_back(arr[left++]);
    } else {
      vec.push_back(arr[right++]);
      inv += mid - left + 1;
    }
  }
  while (left <= mid) {
    vec.push_back(arr[left++]);
  }
  while (right <= e) {
    vec.push_back(arr[right++]);
  }
  for (int i = s; i <= e; i++) {
    arr[i] = vec[i - s];
  }

  return inv;
}

int mergeSort(int *arr, int s, int e) {
  int inv = 0;
  if (s >= e) return inv;
  int mid = s + (e - s) / 2;
  inv += mergeSort(arr, s, mid);
  inv += mergeSort(arr, mid + 1, e);
  inv += mergeArr(arr, s, e, mid);
  return inv;
}

int main() {
  int arr[10] = {4, 3, 7, 1, 9, 3, 6, 0, 5, -1};

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  int inv = mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Inversion: " << inv << endl;
  return 0;
}
