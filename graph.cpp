#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int src, int dest) { adj[src].push_back(dest); }

void printAdjacencyList(vector<int> adj[]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      cout << i << " -> " << adj[i][j] << endl;
    }
  }
}

void transpose(vector<int> adj[], vector<int> trans[]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      trans[adj[i][j]].push_back(i);
    }
  }
}

int main() {
  vector<int> adj[5];
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 4);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 0);
  addEdge(adj, 3, 2);
  addEdge(adj, 4, 1);
  addEdge(adj, 4, 3);
  printAdjacencyList(adj);
  cout << endl;

  vector<int> trans[5];
  transpose(adj, trans);
  printAdjacencyList(trans);

  return 0;
}
