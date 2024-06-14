#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> nums, int index, vector<int> output,
           vector<vector<int>>& answer) {
  if (index >= nums.size()) {
    answer.push_back(output);
    return;
  }
  solve(nums, index + 1, output, answer);

  output.push_back(nums[index]);
  solve(nums, index + 1, output, answer);
}

int main() {
  vector<int> nums = {1, 2, 3, 4};
  vector<int> output;
  vector<vector<int>> answer;
  int index = 0;

  solve(nums, index, output, answer);

  cout << "Array: {";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i];
    if (i != nums.size() - 1) cout << ",";
  }
  cout << "}" << endl << "Total elements: " << answer.size() << endl;
  for (int i = 0; i < answer.size(); i++) {
    cout << "{";
    for (int j = 0; j < answer[i].size(); j++) {
      cout << answer[i][j];
      if (j != answer[i].size() - 1) cout << ",";
    }
    cout << "}" << endl;
  }
  return 0;
}
