#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
  int V;
  list<int> *adj;

public:
  Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void bfs() {
    queue<int> q;
    vector<bool> visited(V, false);

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
      int u = q.front();

      q.pop();
      cout << u << " ";

      for (int v : adj[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }

    cout << "\n";
  }

  void dfsHelper(int u, vector<bool> &visited) {
    cout << u << " ";
    visited[u] = true;

    for (int v : adj[u]) {
      if (!visited[v]) {
        dfsHelper(v, visited);
      }
    }
  }

  void dfs() {
    int src = 0;
    vector<bool> visited(V, false);

    for (int v = 0; v < V; v++) {
      if (!visited[v]) {
        dfsHelper(src, visited);
      }
    }

    cout << "\n";
  }
};
