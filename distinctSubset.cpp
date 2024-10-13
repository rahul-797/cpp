#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> ans;
void subset(vector<int>& v, vector<int> temp, int index) {
  ans.push_back(temp);
  for (int i = index; i < v.size(); i++) {
    if (i > index && v[i] == v[i - 1]) continue;
    temp.push_back(v[i]);
    subset(v, temp, i + 1);
    temp.pop_back();
  }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  subset(nums, vector<int>(), 0);
  return ans;
}
