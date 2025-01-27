#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {
  float *buckets[n];
  int count[n];

  for (int i = 0; i < n; i++) {
    buckets[i] = (float *)malloc(n * sizeof(float));
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    int bucketIndex = n * arr[i];
    buckets[bucketIndex][count[bucketIndex]++] = arr[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < count[i] - 1; j++) {
      for (int k = 0; k < count[i] - j - 1; k++) {
        if (buckets[i][k] > buckets[i][k + 1]) {
          float temp = buckets[i][k];
          buckets[i][k] = buckets[i][k + 1];
          buckets[i][k + 1] = temp;
        }
      }
    }
  }

  int index = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < count[i]; j++) {
      arr[index++] = buckets[i][j];
    }
    free(buckets[i]);
  }
}

int main() {
  float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.34};
  int n = sizeof(arr) / sizeof(arr[0]);

  bucketSort(arr, n);

  printf("Sorted array using Bucket Sort: ");
  for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
  return 0;
}
