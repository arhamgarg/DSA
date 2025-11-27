#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
  string value;
  vector<pair<string, int>> adj;
};

class Graph {
  void DFSUtil(string &v, unordered_set<string> &visited) {
    visited.insert(v);
    cout << v << " ";

    for (auto &p : nodes[v].adj) {
      if (visited.find(p.first) == visited.end()) {
        DFSUtil(p.first, visited);
      }
    }
  }

  string findParent(string v, unordered_map<string, string> &parent) {
    if (parent[v] != v) {
      parent[v] = findParent(parent[v], parent);
    }

    return parent[v];
  }

  void unionSet(string u, string v, unordered_map<string, string> &parent,
                unordered_map<string, int> &rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u != v) {
      if (rank[u] < rank[v]) {
        parent[u] = v;
      } else if (rank[u] > rank[v]) {
        parent[v] = u;
      } else {
        parent[v] = u;
        rank[u]++;
      }
    }
  }

public:
  unordered_map<string, Node> nodes;
  vector<tuple<int, string, string>> edges;
  unordered_set<string> vertices;

  void insertNode(string &e) {
    if (nodes.find(e) == nodes.end()) {
      Node node;

      node.value = e;
      nodes[e] = node;
      vertices.insert(e);
    }
  }

  void insertEdge(string &v1, string &v2, int w) {
    if (nodes.find(v1) == nodes.end() || nodes.find(v2) == nodes.end()) {
      cout << "Vertex not found\n";
      return;
    }

    for (auto &p : nodes[v1].adj) {
      if (p.first == v2) {
        cout << "Edge " << v1 << "-" << v2 << " already exists\n";
        return;
      }
    }

    nodes[v1].adj.push_back({v2, w});
    nodes[v2].adj.push_back({v1, w});
    edges.push_back({w, v1, v2});
  }

  void DFS(string &start) {
    unordered_set<string> visited;

    DFSUtil(start, visited);
    cout << "\n";
  }

  void BFS(string &start) {
    unordered_set<string> visited;
    queue<string> q;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
      string node = q.front();

      q.pop();
      cout << node << " ";

      for (auto &p : nodes[node].adj) {
        if (visited.find(p.first) == visited.end()) {
          visited.insert(p.first);
          q.push(p.first);
        }
      }
    }

    cout << "\n";
  }

  void Prim(string &start) {
    if (nodes.find(start) == nodes.end()) {
      cout << "Invalid start vertex\n";
      return;
    }

    unordered_set<string> visited;

    visited.insert(start);

    using Edge = tuple<int, string, string>;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (auto &p : nodes[start].adj) {
      pq.push({p.second, start, p.first});
    }

    vector<Edge> mst;
    int totalWeight = 0;

    while (!pq.empty() && visited.size() < vertices.size()) {
      auto [w, u, v] = pq.top();

      pq.pop();

      if (visited.find(v) != visited.end()) {
        continue;
      }

      visited.insert(v);
      mst.push_back({w, u, v});
      totalWeight += w;

      for (auto &p : nodes[v].adj) {
        if (visited.find(p.first) == visited.end()) {
          pq.push({p.second, v, p.first});
        }
      }
    }

    cout << "\nMST (Prim's):\n";

    for (auto &[w, u, v] : mst) {
      cout << u << " -- " << v << " weight = " << w << "\n";
    }

    cout << "Total Weight: " << totalWeight << "\n\n";
  }

  void Kruskal() {
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

    for (auto &v : vertices) {
      parent[v] = v;
      rank[v] = 0;
    }

    using Edge = tuple<int, string, string>;
    vector<Edge> sortedEdges = edges;

    sort(sortedEdges.begin(), sortedEdges.end());

    vector<Edge> mst;
    int totalWeight = 0;

    for (auto &[w, u, v] : sortedEdges) {
      string ru = findParent(u, parent);
      string rv = findParent(v, parent);

      if (ru != rv) {
        unionSet(ru, rv, parent, rank);
        mst.push_back({w, u, v});
        totalWeight += w;
      }
    }

    cout << "\nMST (Kruskal's):\n";

    for (auto &[w, u, v] : mst) {
      cout << u << " -- " << v << " weight = " << w << "\n";
    }

    cout << "Total Weight: " << totalWeight << "\n\n";
  }

  void ShortestPath(string &start) {
    if (nodes.find(start) == nodes.end()) {
      cout << "Invalid start vertex\n";
      return;
    }

    unordered_map<string, int> dist;
    unordered_map<string, string> parent;

    for (auto &v : vertices) {
      dist[v] = INT_MAX;
      parent[v] = "";
    }

    dist[start] = 0;

    using P = pair<int, string>;
    priority_queue<P, vector<P>, greater<P>> pq;

    pq.push({0, start});

    while (!pq.empty()) {
      auto [d, u] = pq.top();

      pq.pop();

      if (d > dist[u]) {
        continue;
      }

      for (auto &p : nodes[u].adj) {
        int newDist = d + p.second;

        if (newDist < dist[p.first]) {
          dist[p.first] = newDist;
          parent[p.first] = u;
          pq.push({newDist, p.first});
        }
      }
    }

    cout << "\nShortest paths from " << start << ":\n";

    for (auto &v : vertices) {
      if (dist[v] == INT_MAX) {
        cout << start << " -> " << v << ": No path\n";
      } else {
        vector<string> path;

        for (string node = v; !node.empty(); node = parent[node]) {
          path.insert(path.begin(), node);
        }

        cout << start << " -> " << v << ": Distance = " << dist[v]
             << ", Path = ";

        for (size_t i = 0; i < path.size(); i++) {
          cout << path[i];

          if (i != path.size() - 1) {
            cout << " -> ";
          }
        }

        cout << "\n";
      }
    }
  }

  void printGraph() {
    cout << "\nGraph Adjacency List:\n";

    for (auto &kv : nodes) {
      cout << kv.first << ": ";

      for (auto &p : kv.second.adj) {
        cout << "(" << p.first << ", " << p.second << ") ";
      }

      cout << "\n";
    }

    cout << "\n";
  }
};

int main() {
  Graph graph;

  int inputs;
  cin >> inputs;
  cin.ignore();

  while (inputs-- > 0) {
    string cmd;
    getline(cin, cmd);
    vector<string> op;
    string temp;

    for (auto c : cmd) {
      if (c == ' ') {
        if (!temp.empty()) {
          op.push_back(temp);
        }

        temp.clear();
      } else {
        temp += c;
      }
    }

    if (!temp.empty()) {
      op.push_back(temp);
    }

    if (op[0] == "IN") {
      graph.insertNode(op[1]);
    } else if (op[0] == "IE") {
      graph.insertEdge(op[1], op[2], stoi(op[3]));
      graph.printGraph();
    } else if (op[0] == "DFS") {
      graph.DFS(op[1]);
    } else if (op[0] == "BFS") {
      graph.BFS(op[1]);
    } else if (op[0] == "PRIM") {
      graph.Prim(op[1]);
    } else if (op[0] == "KRUSKAL") {
      graph.Kruskal();
    } else if (op[0] == "DIJKSTRA") {
      graph.ShortestPath(op[1]);
    }

    return 0;
  }
}
