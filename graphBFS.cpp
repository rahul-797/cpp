#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int src, int dest) { adj[src].push_back(dest); }

bool addVisited(vector<int>& visited, int val) {
  if (find(visited.begin(), visited.end(), val) != visited.end()) {
    return false;
  } else {
    visited.push_back(val);
    return true;
  }
}

void traverseGraph(vector<int> adj[], deque<int>& q, vector<int>& visited) {
  if (q.empty()) return;
  int front = q.front();
  addVisited(visited, front);
  q.pop_front();
  for (int i = front; i < adj[front].size(); i++) {
    if (find(q.begin(), q.end(), adj[front][i]) == q.end())
      q.push_back(adj[front][i]);
  }
  return traverseGraph(adj, q, visited);
}

int main() {
  vector<int> adj[6];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 0);
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 0);
  addEdge(adj, 2, 1);
  addEdge(adj, 2, 4);
  addEdge(adj, 3, 1);
  addEdge(adj, 3, 4);
  addEdge(adj, 4, 2);
  addEdge(adj, 4, 3);

  vector<int> visited;
  deque<int> q;
  q.push_back(0);
  traverseGraph(adj, q, visited);

  for (int i : visited) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
