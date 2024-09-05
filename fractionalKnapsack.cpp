#include <bits/stdc++.h>
using namespace std;

struct Item {
  int value;
  int weight;
};

class Solution {
 public:
  double fractionalKnapsack(int w, Item arr[], int n) {
    vector<pair<float, float>> vec;

    for (int i = 0; i < n; i++) {
      float weight = arr[i].weight;
      float val = arr[i].value / weight;
      vec.push_back(make_pair(val, arr[i].weight));
    }

    sort(vec.rbegin(), vec.rend());

    float knapsack = 0;
    float weight = 0;
    for (int i = 0; i < n; i++) {
      if (weight == w) break;
      if (weight + vec[i].second <= w) {
        weight += vec[i].second;
        knapsack += (vec[i].first * vec[i].second);
      } else {
        knapsack +=
            ((w - weight) * (vec[i].first * vec[i].second) / vec[i].second);
        weight = w;
        break;
      }
    }
    return knapsack;
  }
};

int main() {
  int t;
  cin >> t;
  cout << setprecision(6) << fixed;
  while (t--) {
    int n, W;
    cin >> n >> W;
    Item arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i].value >> arr[i].weight;
    }
    Solution ob;
    cout << ob.fractionalKnapsack(W, arr, n) << endl;
  }
  return 0;
}
