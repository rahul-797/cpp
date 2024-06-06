#include <iostream>
using namespace std;

int main() {
  int a = 100;
  int *p;
  *p = a;
  a++;
  cout << *p << endl;
  return 0;
}
