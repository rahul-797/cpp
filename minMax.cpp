#include <climits>
#include <iostream>
using namespace std;

int calc(int* arr, int len, int& min, int& max) {
  int m = 0, M = 0;
  if (arr[0] < arr[1])
    min = arr[0], max = arr[1];
  else
    min = arr[1], max = arr[0];
  int count = 1;

  for (int i = 2; i < len; i += 2, count += 3) {
    if (arr[i] < arr[i + 1]) {
      m = arr[i], M = arr[i + 1];
    } else {
      m = arr[i + 1], M = arr[i];
    }
    if (m < min) min = m;
    if (M > max) max = M;
  }
  return count;
}

int main() {
  int arr[10] = {3, 5, 1, 8, 4, 2, 9, 0, 6, 7};
  int min = INT_MAX, max = INT_MIN;
  int comparisons = calc(arr, sizeof(arr) / sizeof(arr[0]), min, max);

  cout << "Array: " << endl;
  for (auto i : arr) {
    cout << i << " ";
  }
  cout << endl;

  cout << "Min: " << min << endl
       << "Max: " << max << endl
       << "Comparisons: " << comparisons << endl;
  return 0;
}
