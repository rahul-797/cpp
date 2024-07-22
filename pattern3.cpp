#include <iostream>
using namespace std;

int main() {
  int num = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < num; j++) {
      if (j <= i)
        cout << j + 1;
      else
        cout << " ";
    }
    for (int j = num; j > 0; j--) {
      if (j > i + 1)
        cout << " ";
      else
        cout << j;
    }
    cout << "\n";
  }
  return 0;
}
