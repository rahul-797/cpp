#include <algorithm>
#include <deque>
#include <iostream>
#include <ostream>
#include <stack>
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

void graphDFS(vector<int> adj[], int pos, vector<int>& visited) {
  visited.push_back(pos);
  cout << pos << " ";
  vector<int>::iterator i;
  for (i = adj[pos].begin(); i != adj[pos].end(); i++) {
    if (find(visited.begin(), visited.end(), *i) == visited.end()) {
      graphDFS(adj, *i, visited);
    }
  }
}

void graphDFSIterative(vector<int> adj[], int pos, vector<int>& visited) {
  visited.clear();
  stack<int> s;
  s.push(pos);
  while (!s.empty()) {
    int top = s.top();
    s.pop();
    if (find(visited.begin(), visited.end(), top) == visited.end()) {
      cout << top << " ";
      visited.push_back(top);
    }
    vector<int>::iterator i;
    for (i = adj[top].begin(); i != adj[top].end(); i++) {
      if (find(visited.begin(), visited.end(), *i) == visited.end()) {
        s.push(*i);
      }
    }
  }
}

int main() {
  vector<int> adj[6];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 1, 2);
  addEdge(adj, 3, 2);
  addEdge(adj, 3, 3);

  vector<int> visited;
  uniToBiDirectional(adj);
  graphDFS(adj, 0, visited);
  cout << endl;
  graphDFSIterative(adj, 0, visited);

  return 0;
}
