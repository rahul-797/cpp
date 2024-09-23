// You are given timings of n meetings in the form of (start[i], end[i]) where
// start[i] is the start time of meeting i and end[i] is the finish time of
// meeting i. Return the maximum number of meetings that can be accommodated in
// a single meeting room, when only one meeting can be held in the meeting room
// at a particular time.
//
// Note: The start time of one chosen meeting can't be equal to the end time of
// the other chosen meeting.

#include <bits/stdc++.h>
using namespace std;

struct meeting {
  int pos;
  int start;
  int end;
};

class Solution {
 public:
  bool static comparator(struct meeting m1, struct meeting m2) {
    if (m1.end < m2.end)
      return true;
    else if (m1.end > m2.end)
      return false;
    return m1.pos < m2.pos;
  }

  static int maxMeetings(int n, int start[], int end[]) {
    struct meeting meet[n];
    for (int i = 0; i < n; i++) {
      meet[i].pos = i + 1;
      meet[i].start = start[i];
      meet[i].end = end[i];
    }
    sort(meet, meet + n, comparator);
    vector<int> answer;
    answer.push_back(meet[0].pos);
    int limit = meet[0].end;

    for (int i = 1; i < n; i++) {
      if (meet[i].start > limit) {
        answer.push_back(meet[i].pos);
        limit = meet[i].end;
      }
    }
    return answer.size();
  }
};

int main() {
  int n = 6;
  int start[] = {1, 3, 0, 5, 8, 5};
  int end[] = {2, 4, 5, 7, 9, 9};
  int result = Solution::maxMeetings(n, start, end);
  cout << result << endl;
  return 0;
}
