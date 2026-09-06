#include <stack>
#include <vector>
using namespace std;

vector<int> depthFirstSearch(const vector<vector<int>> &graph, int start) {
  vector<int> traversal;
  vector<bool> visited(graph.size(), false);
  stack<int> nodes;

  nodes.push(start);

  while (!nodes.empty()) {
    int node = nodes.top();
    nodes.pop();

    if (visited[node]) {
      continue;
    }

    visited[node] = true;
    traversal.push_back(node);

    for (auto neighbor = graph[node].rbegin(); neighbor != graph[node].rend();
         ++neighbor) {
      if (!visited[*neighbor]) {
        nodes.push(*neighbor);
      }
    }
  }

  return traversal;
}
