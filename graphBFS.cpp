#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int src, int dest) {
  for (int i = 0; i < adj[src].size(); i++) {
    if (adj[src][i] == dest) return;
  }
  adj[src].push_back(dest);
}

void printAdjacencyList(vector<int> adj[]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      cout << i << " -> " << adj[i][j] << endl;
    }
  }
}

void uniToBiDirectional(vector<int> adj[]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      addEdge(adj, adj[i][j], i);
    }
  }
}

bool addVisited(vector<int>& visited, int val) {
  if (find(visited.begin(), visited.end(), val) != visited.end()) {
    return false;
  } else {
    visited.push_back(val);
    return true;
  }
}

void print_queue(deque<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop_front();
  }
  cout << endl;
}

void traverseGraph(vector<int> adj[], deque<int>& q, vector<int>& visited) {
  if (q.empty()) return;
  int front = q.front();
  addVisited(visited, front);
  q.pop_front();
  for (int i = 0; i < adj[front].size(); i++) {
    if (find(visited.begin(), visited.end(), adj[front][i]) == visited.end()) {
      q.push_back(adj[front][i]);
    }
  }
  return traverseGraph(adj, q, visited);
}

int main() {
  vector<int> adj[6];
  addEdge(adj, 2, 0);
  addEdge(adj, 0, 1);
  addEdge(adj, 2, 3);

  vector<int> visited;
  deque<int> q;
  q.push_back(0);
  uniToBiDirectional(adj);
  traverseGraph(adj, q, visited);

  for (int i : visited) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
