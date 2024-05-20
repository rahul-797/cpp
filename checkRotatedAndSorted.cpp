#include <iostream>
using namespace std;

int main() {
  int arr[10] = {4, 5, 6, 7, 8, 9, 0, 1, 0, 3};
  int len = sizeof(arr) / sizeof(arr[0]);
  int indexOfRotation = 0;

  for (int i = 0; i < len - 1; i++) {
    if (arr[i + 1] < arr[i]) {
      indexOfRotation = i + 1;
      break;
    };
  }
  cout << indexOfRotation << endl;

  int i = indexOfRotation;
  bool isRotatedAndSorted = true;
  for (int j = 0; j < len - 1; j++, i++) {
    if (arr[i % len] <= arr[(i + 1) % len])
      continue;
    else {
      isRotatedAndSorted = false;
      break;
    }
  }

  if (isRotatedAndSorted)
    cout << "Yes, rotated and sorted" << endl;
  else
    cout << "Not rotated and sorted" << endl;

  return 0;
}
