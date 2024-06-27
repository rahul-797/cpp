#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int shift(vector<int>& vec, int& val) {
  if (vec.size() == 0) return 0;
  auto front = vec.begin();
  auto end = vec.end();
  end--;
  while (front <= end) {
    if (*end == val) {
      end--;
      continue;
    }
    if (*front != val) {
      front++;
      continue;
    }
    int temp = *front;
    *front = *end;
    *end = temp;
  }
  auto it = find(vec.begin(), vec.end(), val);
  int k = distance(vec.begin(), it);
  return k;
}

int main() {
  vector<int> vec = {1, 3, 2, 2, 4, 7, 8, 9, 0, 2, 1, 2};
  int val = 2;
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
  int k = shift(vec, val);
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
  cout << "Elements before " << val << ": " << k << endl;
  return 0;
}
