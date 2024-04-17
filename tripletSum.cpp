#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  double len = (double)sizeof(arr) / sizeof(arr[0]);
  int length = ceil(len / 3);
  int newArr[length];
  int j = 0;
  int mod = (int)len % 3;

  for (int i = 0; i < len - mod; i += 3) {
    newArr[j] = arr[i] + arr[i + 1] + arr[i + 2];
    j++;
  }

  switch (mod) {
    case 1:
      newArr[length - 1] = arr[(int)len - 1];
      break;
    case 2:
      newArr[length - 1] = arr[(int)len - 1] + arr[(int)len - 2];
      break;
  }

  for (int i = 0; i < length; i++) {
    cout << newArr[i] << " ";
  }
  cout << endl;

  return 0;
}
