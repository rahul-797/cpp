#include <cstdlib>
#include <iostream>

#define fr(s, e) for (int i = s; i < e; i++)
#define n 10
using namespace std;

int* arr = (int*)calloc(10, sizeof(int));
int* count = (int*)calloc(10, sizeof(int));

int root(int a) {
  while (arr[a] != a) {
    arr[a] =
        arr[arr[a]];  // point each node to grandparent ie shorten path to root
    a = arr[a];
  }
  return a;
}

void connect(int a, int b) {
  int r1 = root(a);
  int r2 = root(b);
  if (r1 == r2) return;
  // add smaller tree to bigger tree to make it balanced
  // now find takes atmost logn time
  if (count[r1] < count[r2]) {
    arr[r2] = r1;
    count[r2] += count[r1];
    return;
  }
  arr[r1] = r2;
  count[r1] += count[r2];
}

bool isConnected(int a, int b) { return root(a) == root(b); }

int main() {
  fr(0, n) arr[i] = i;
  connect(0, 2);
  connect(3, 2);
  connect(5, 9);
  connect(2, 4);
  fr(0, n) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
