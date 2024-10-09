#include <cstdlib>
#include <ctime>
#include <iostream>

#define fr(s, e) for (int i = s; i < e; i++)
#define n 10
using namespace std;

int** arr = (int**)malloc(10 * sizeof(int*));
int open = 0;

void printArr() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

int root(int a) {
  int one = a % 10;
  int ten = (a / 10) % 10;
  while (arr[ten][one] != a) {
    int pone = arr[ten][one] % 10;
    int pten = (arr[ten][one] / 10) % 10;
    arr[ten][one] = arr[ten][one];
    a = arr[ten][one];
  }
  return a;
}

void connect(int a, int b) {}

bool isConnected(int a) { return root(a) == -1; }

bool isPercolated() {
  fr(0, n) {
    if (isConnected(arr[n - 1][i])) return true;
  }
  return false;
}

int main() {
  srand(time(NULL));
  fr(0, n) arr[i] = (int*)malloc(10 * sizeof(int));

  // initialise arr
  int temp = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0) {
        arr[i][j] = -1;
        continue;
      }
      arr[i][j] = temp++;
    }
  }

  while (!isPercolated()) {
  }
  return 0;
}
