/*
You have been given a number of stairs. Initially, you are at the 0th stair, and
you need to reach the Nth stair. Each time, you can climb either one step or two
steps. You are supposed to return the number of distinct ways you can climb from
the 0th step to the Nth step.
*/

#include <iostream>
using namespace std;

long countDistinctWays(int nStairs) {
  if (nStairs == 0) return 1;
  if (nStairs <= 3) return nStairs;
  return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}

int main() {
  int stairCount;
  cin >> stairCount;
  long ways = countDistinctWays(stairCount);
  cout << "Number of ways to reach " << stairCount << " stairs is: " << ways
       << endl;
  return 0;
}
