#include <iostream>
#include <queue>
using namespace std;

int main() {
  int arr[37] = {0, 2, 5, 3, 3, 4, 4, 3, 0, 5, 5, 4, 4, 4, 3, 2, 0, 2, 3,
                 1, 3, 0, 4, 3, 1, 4, 5, 2, 4, 3, 1, 4, 5, 0, 3, 4, 0};
  int k = 52;
  int len = sizeof(arr) / sizeof(arr[0]);
  int counter = 0;
  int currSum = 0;
  int max = 0;

  queue<int> q;
  while (counter < len) {
    if (currSum == k) {
      if (q.size() > max) max = q.size();
      if (arr[counter] == 0) {
        q.push(arr[counter]);
        counter++;
        if (q.size() > max) max = q.size();
        continue;
      }
      currSum -= q.front();
      q.pop();
    }
    if (currSum < k) {
      q.push(arr[counter]);
      currSum += arr[counter];
      counter++;
    }
    if (currSum > k) {
      currSum -= q.front();
      q.pop();
    }
  }

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  cout << "Max subarray length: " << max << endl;

  return 0;
}
