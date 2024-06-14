#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int partitionVec(vector<int>& vec, int s, int e) {
  int count = 0;
  // we calculate elements >= initial element, here = is important
  // as we want our element at last and even all equal elements must be before
  // it

  for (int i = s + 1; i <= e; i++) {
    if (vec[i] <= vec[s]) count++;
  }
  int pivotIndex = s + count;
  swap(vec[s], vec[pivotIndex]);

  int first = s, last = e;
  while (first < pivotIndex && last > pivotIndex) {
    if (vec[first] <= vec[s + count]) {
      first++;
    }
    if (vec[last] > vec[s + count]) {
      last--;
    }
    // put all <= elements before pivot
    if (vec[first] > vec[pivotIndex] && vec[last] <= vec[pivotIndex])
      swap(vec[first++], vec[last--]);
  }
  return pivotIndex;
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
