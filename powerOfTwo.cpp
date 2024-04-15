#include <iostream>

using namespace std;

int main() {
  int n, number = 1;
  cin >> n;
  bool isPower = false;

  if (n == 1) {
    cout << "true" << endl;
    return 0;
  }

  for (int i = 1; i <= 32; i++) {
    if (n == (number << 1)) {
      isPower = true;
      break;
    }
    number = number << 1;
  }
  if (isPower) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
  return 0;
}
