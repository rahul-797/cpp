#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int left, int right) {
  int pivot = arr[right];
  int i = left;
  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[right]);
  return i;
}

int randomizedPartition(int arr[], int left, int right) {
  int randomIndex = left + rand() % (right - left + 1);
  swap(&arr[randomIndex], &arr[right]);
  return partition(arr, left, right);
}

int randomizedSelect(int arr[], int left, int right, int i) {
  if (left == right) return arr[left];

  int pivotIndex = randomizedPartition(arr, left, right);
  int k = pivotIndex - left + 1;

  if (i == k)
    return arr[pivotIndex];
  else if (i < k)
    return randomizedSelect(arr, left, pivotIndex - 1, i);
  else
    return randomizedSelect(arr, pivotIndex + 1, right, i - k);
}

int main() {
  int arr[] = {12, 3, 5, 7, 19, 26, 23, 10, 15, 17};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i = 4;
  printf("The %d-th smallest element is %d\n", i,
         randomizedSelect(arr, 0, n - 1, i));
  return 0;
}
