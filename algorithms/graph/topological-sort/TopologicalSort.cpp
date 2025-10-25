#include <iostream>
#include <list>
#include <stack>
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

  void addEdge(int u, int v) { adj[u].push_back(v); }

  void dfs(int u, vector<bool> &visited, stack<int> &s) {
    visited[u] = true;

    for (int v : adj[u]) {
      if (!visited[v]) {
        dfs(v, visited, s);
      }
    }

    s.push(u);
  }

  void topologicalSort() {
    vector<bool> visited(V, false);
    stack<int> s;

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        dfs(i, visited, s);
      }
    }

    while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }

    cout << "\n";
  }
};
