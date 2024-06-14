#include <iostream>
#include <vector>
using namespace std;

void mergeArr(int *arr, int s, int e, int mid) {
  int left = s;
  int right = mid + 1;
  vector<int> vec;

  while (left <= mid && right <= e) {
    if (arr[left] <= arr[right]) {
      vec.push_back(arr[left++]);
    } else {
      vec.push_back(arr[right++]);
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
}

void mergeSort(int *arr, int s, int e) {
  if (s >= e) return;
  int mid = s + (e - s) / 2;
  mergeSort(arr, s, mid);
  mergeSort(arr, mid + 1, e);
  mergeArr(arr, s, e, mid);
}

int main() {
  int arr[10] = {4, 3, 7, 1, 9, 3, 6, 0, 5, -1};

  mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
