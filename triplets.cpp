#include <math.h>

#include <cmath>
#include <iostream>
using namespace std;

int main() {
  for (float h = 1; h < 30; h++) {
    for (float b = 1; b < h; b++) {
      float pSquare = h * h - b * b;
      float p = sqrt(pSquare);
      if (ceilf(p) == p)
        cout << "Hypotenuse: " << h << " Base: " << b << " Perpendicular: " << p
             << endl;
    }
  }
  cout << endl;
  return 0;
}
