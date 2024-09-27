#include <iostream>

#define fr(s, e) for (int i = s; i < e; i++)
#define n 10
using namespace std;

int arr[n];

void connect(int a, int b) {
  int aid = arr[a], bid = arr[b];
  if (aid == bid) return;
  fr(0, n) if (arr[i] == aid) arr[i] = bid;
}

bool connected(int a, int b) { return arr[a] == arr[b]; }

int main() {
  fr(0, n) arr[i] = i;
  connect(1, 2);
  connect(3, 4);
  connect(4, 5);
  connect(6, 5);
  connect(1, 9);

  cout << "Is 2 and 3 connected: " << connected(2, 3) << endl;
  cout << "Is 1 and 9 connected: " << connected(1, 9) << endl;
  cout << "Is 6 and 5 connected: " << connected(6, 5) << endl;

  cout << "The connected parts: " << endl;
  /* fr(0, n) cout << arr[i] << " "; */
  /* cout << endl; */
  return 0;
}
