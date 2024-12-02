#include <iostream>
#include <vector>

#define fr(s, e) for (int i = s; i < e; i++)
using namespace std;

// count the end element or not
bool count(vector<int>& a, int sum, int n) {
  if (sum == 0) return true;
  if (n == 0) return false;
  if (a[n] > sum) return count(a, sum, n - 1);
  return count(a, sum, n - 1) || count(a, sum - a[n], n - 1);
}

bool isSubsetPresent(int k, vector<int>& a) {
  return count(a, k, a.size() - 1);
}

int main() {
  vector<int> a = {22, 17, 19, 46, 48, 27, 22, 39, 20, 13, 18, 50, 36, 45,
                   4,  12, 23, 34, 24, 15, 42, 12, 4,  19, 48, 45, 13, 8,
                   38, 10, 24, 42, 30, 29, 17, 36, 41, 43, 39, 7,  41, 43,
                   15, 49, 47, 6,  41, 30, 21, 1,  7,  2,  44, 49, 30, 24,
                   35, 5,  7,  41, 17, 27, 32, 9,  45, 40, 27, 24, 38, 39,
                   19, 33, 30, 42, 34, 16, 40, 9,  5,  31, 28, 7,  24, 37,
                   22, 46, 25, 23, 21, 30, 28, 24, 48, 13};
  cout << "Is subset present: " << isSubsetPresent(84, a);
  cout << endl;
  return 0;
}
