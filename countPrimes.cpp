#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int num = 90;
  vector<int> vec;
  for (int i = 2; i < num; i++) {
    vec.push_back(i);
  }
  for (int i : vec) {
    cout << i << " ";
  }
  cout << endl;
  for (int i = 0; i < num; i++) {
    for (int j = 2; vec[i] * j < vec.back(); j++) {
      vec.erase(remove(vec.begin(), vec.end(), vec[i] * j), vec.end());
    }
    cout << "Removed multiples of: " << vec[i] << "  ->   ";
    for (int a : vec) {
      cout << a << " ";
    }
    cout << endl;
    if (vec[i] == vec.back()) break;
  }
  return 0;
}
