#include <iostream>
using namespace std;

int main (int argc, char *argv[]) {
  int n;
  std::cin >> n;
  int i = 1;
  while (i<=n) {
    int j = 1;
    int stars = (i-1)*2;
    while (j<=n-i+1) {
      std::cout << j;
      j+=1;
    }
    
    while (stars) {
      stars-=1;
      std::cout << "*";
    }

    while (j>1) {
      j-=1;
      std::cout << j;
    }
    i+=1;
    std::cout << endl;
  }
  return 0;
}
