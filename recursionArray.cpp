#include <algorithm>
#include <iostream>
using namespace std;

int sum(int *arr, int size) {
  if (size == 0) return 0;
  return arr[0] + sum(arr + 1, size - 1);
}

bool isSorted(int *arr, int size) {
  if (size == 0 || size == 1) {
    cout << "Sorted" << endl;
    return true;
  }
  if (arr[0] > arr[1]) {
    cout << "Not sorted" << endl;
    return false;
  }
  return isSorted(arr + 1, size - 1);
}

bool linearSearch(int *arr, int size, int key) {
  if (size == 0) {
    cout << "Not found" << endl;
    return false;
  }
  if (arr[0] == key) {
    cout << "Found" << endl;
    return true;
  }
  return linearSearch(arr + 1, size - 1, key);
}

int binarySearch(int *arr, int key, int start, int end) {
  if (start > end) {
    return -1;
  }
  int mid = start + (end - start) / 2;
  if (key == arr[mid]) return mid;
  if (key < arr[mid])
    return binarySearch(arr, key, start, mid - 1);
  else
    return binarySearch(arr, key, mid + 1, end);
}

int main() {
  int arr[6] = {1, 2, 3, 4, 5, 6};
  int size = sizeof(arr) / sizeof(arr[0]);
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;
  isSorted(arr, size);
  cout << "Sum of elements is: " << sum(arr, size) << endl;
  cout << "Enter element to search(linear search): ";
  int key;
  cin >> key;
  linearSearch(arr, size, key);
  cout << "Enter element to search(binary search): ";
  int key2;
  cin >> key2;
  sort(arr, arr + size);
  int index = binarySearch(arr, key2, 0, size - 1);
  cout << "Found at index: " << index << endl;
  return 0;
}
