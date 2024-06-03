#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<vector<int>>& arr, int num) {
  int rows = arr.size();
  int cols = arr[0].size();
  int s = 0;
  int e = rows * cols - 1;
  int mid = s + (e - s) / 2;
  while (s <= e) {
    int value = arr[mid / cols][mid % cols];
    if (value == num) return true;
    if (value < num)
      s = mid + 1;
    else
      e = mid - 1;
    mid = s + (e - s) / 2;
  }
  return false;
}

int main() {
  vector<vector<int>> arr;
  int count = 1;
  for (int i = 0; i < 4; i++) {
    arr.push_back(vector<int>());
    for (int j = 0; j < 5; j++) {
      arr[i].push_back(count++);
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  int num;
  cout << "Enter an element to search: ";
  cin >> num;
  bool found = binarySearch(arr, num);
  cout << found << endl;
  return 0;
}
