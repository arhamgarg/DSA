#include <vector>

using namespace std;

void dfs(const vector<vector<int>> &graph, int node, vector<bool> &visited,
         vector<int> &traversal) {
  visited[node] = true;
  traversal.push_back(node);

  for (int neighbor : graph[node]) {
    if (!visited[neighbor]) {
      dfs(graph, neighbor, visited, traversal);
    }
  }
}

vector<int> depthFirstSearch(const vector<vector<int>> &graph, int start) {
  vector<int> traversal;
  vector<bool> visited(graph.size(), false);

  dfs(graph, start, visited, traversal);
  return traversal;
}
