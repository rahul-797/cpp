#include <stdio.h>

#define GROUP_SIZE 5

int deterministicSelect(int arr[], int left, int right, int i);
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int left, int right, int pivot) {
  for (int i = left; i < right; i++) {
    if (arr[i] == pivot) {
      swap(&arr[i], &arr[right]);
      break;
    }
  }

  int pivotValue = arr[right];
  int i = left;
  for (int j = left; j < right; j++) {
    if (arr[j] <= pivotValue) {
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[right]);
  return i;
}

void insertionSort(int arr[], int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= left && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int findMedian(int arr[], int left, int right) {
  int size = right - left + 1;
  return arr[left + size / 2];
}

int selectPivot(int arr[], int left, int right) {
  if (right - left + 1 <= GROUP_SIZE) {
    insertionSort(arr, left, right);
    return findMedian(arr, left, right);
  }

  int numGroups = (right - left + 1 + GROUP_SIZE - 1) / GROUP_SIZE;
  int medianIndex = left;

  for (int i = 0; i < numGroups; i++) {
    int groupLeft = left + i * GROUP_SIZE;
    int groupRight = groupLeft + GROUP_SIZE - 1;
    if (groupRight > right) groupRight = right;

    insertionSort(arr, groupLeft, groupRight);
    int median = findMedian(arr, groupLeft, groupRight);
    swap(&arr[medianIndex], &arr[groupLeft + (groupRight - groupLeft) / 2]);
    medianIndex++;
  }

  return deterministicSelect(arr, left, left + numGroups - 1, numGroups / 2);
}

int deterministicSelect(int arr[], int left, int right, int i) {
  if (left == right) return arr[left];

  int pivot = selectPivot(arr, left, right);
  int pivotIndex = partition(arr, left, right, pivot);
  int k = pivotIndex - left + 1;

  if (i == k)
    return arr[pivotIndex];
  else if (i < k)
    return deterministicSelect(arr, left, pivotIndex - 1, i);
  else
    return deterministicSelect(arr, pivotIndex + 1, right, i - k);
}

int main() {
  int arr[] = {12, 3, 5, 7, 19, 26, 23, 10, 15, 17};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i = 5;
  printf("The %d-th smallest element is %d\n", i,
         deterministicSelect(arr, 0, n - 1, i));
  return 0;
}
