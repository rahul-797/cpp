#include <stdio.h>

void max_heapify(int arr[], int n, int i) {
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;
  if (l < n && arr[l] > arr[largest]) largest = l;
  if (r < n && arr[r] > arr[largest]) largest = r;
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    max_heapify(arr, n, largest);
  }
}

void build_max_heap(int arr[], int n) {
  for (int i = n / 2 - 1; i >= 0; i--) max_heapify(arr, n, i);
}

void heap_sort(int arr[], int n) {
  build_max_heap(arr, n);
  for (int i = n - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    max_heapify(arr, i, 0);
  }
}

int main() {
  int arr[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  heap_sort(arr, n);
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
