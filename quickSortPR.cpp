#include <iostream>
#include <utility>
using namespace std;

int part(int* arr, int start, int end) {
  int s = start, e = end;
  int pivot = arr[start];
  while (s < e) {
    while (arr[s] <= pivot && s <= end - 1) {
      s++;
    }
    while (arr[e] > pivot && e >= start + 1) {
      e--;
    }
    if (s < e) swap(arr[s], arr[e]);
  }
  swap(arr[start], arr[e]);
  return e;
}

void quickSort(int* arr, int s, int e) {
  if (s < e) {
    int pivot = part(arr, s, e);
    quickSort(arr, s, pivot - 1);
    quickSort(arr, pivot + 1, e);
  }
}

int main() {
  int arr[10] = {4, 6, 7, 2, 1, 8, 9, 5, 10, 3};
  quickSort(arr, 0, 9);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
