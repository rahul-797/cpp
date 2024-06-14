#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int partitionVec(vector<int>& vec, int s, int e) {
  int count = 0;
  for (int i = s + 1; i <= e; i++) {
    if (vec[i] <= vec[s]) count++;
  }
  swap(vec[s], vec[s + count]);

  int first = s, last = e;
  while (first < s + count && last > s + count) {
    if (vec[first] <= vec[s + count]) {
      first++;
    }
    if (vec[last] > vec[s + count]) {
      last--;
    }
    if (first < s + count && last > s + count) swap(vec[first++], vec[last--]);
  }
  return s + count;
}

void quickSort(vector<int>& vec, int s, int e) {
  int mid = s + (e - s) / 2;
  if (s >= e) return;
  int i = partitionVec(vec, s, e);
  quickSort(vec, s, i - 1);
  quickSort(vec, i + 1, e);
}

int main() {
  vector<int> vec = {7, 7, 7, 1, 7, 1, 2, 1};
  quickSort(vec, 0, vec.size() - 1);
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
