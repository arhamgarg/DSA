#include <queue>
#include <vector>

using namespace std;

vector<int> bfs(const vector<vector<int>> &graph, int start) {
  vector<int> traversal;
  vector<bool> visited(graph.size(), false);
  queue<int> nodes;

  nodes.push(start);
  visited[start] = true;

  while (!nodes.empty()) {
    int node = nodes.front();

    nodes.pop();
    traversal.push_back(node);

    for (int neighbor : graph[node]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        nodes.push(neighbor);
      }
    }
  }

  return traversal;
}
