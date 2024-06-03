#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n = 1000;
  vector<int> vec;
  for (int i = 2; i < n; i++) {
    vec.push_back(i);
  }
  for (int i = 0; i < n && vec[i] <= vec.back() / 2; i++) {
    for (int j = 2; vec[i] * j <= vec.back(); j++) {
      vec.erase(remove(vec.begin(), vec.end(), vec[i] * j), vec.end());
    }
  }
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
  cout << vec.size() << endl;
  return 0;
}
