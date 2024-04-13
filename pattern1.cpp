#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int i = 0;
  while (i<n) {
    int c = 1;
    int space = n-i-1;
    while (space) {
      std::cout << " ";
      space-=1;
    }
    while (c<=i) {
      std::cout << c;
      c+=1;
    }
    while (c>0) {
      std::cout << c;
      c-=1;
    }
    std::cout << endl;
    i+=1;
  }
  return 0;
}
