#include <algorithm>
#include <list>
#include <vector>
using namespace std;

class Graph {
  int V;
  list<int> *adj;
  vector<int> ans;

  void dfs(int u, vector<bool> &visited) {
    visited[u] = true;

    for (int v : adj[u]) {
      if (!visited[v]) {
        dfs(v, visited);
      }
    }

    ans.push_back(u);
  }

public:
  Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
  }

  void addEdge(int u, int v) { adj[u].push_back(v); }

  vector<int> topologicalSort() {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        dfs(i, visited);
      }
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};
