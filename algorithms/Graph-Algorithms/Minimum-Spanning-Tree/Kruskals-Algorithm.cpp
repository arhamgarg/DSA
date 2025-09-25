// kruskal's algorithm for minimum spanning tree (MST)
//
// this algorithm finds the mst of a connected, undirected, and weighted graph.
// it works by sorting all the edges of the graph by weight in non-decreasing
// order. then, it iterates through the sorted edges and adds an edge to the
// mst if it does not form a cycle.
// a disjoint set union (dsu) data structure is used to efficiently detect
// cycles.
//
// time complexity: O(E log E) or O(E log V), dominated by edge sorting.
// space complexity: O(V + E) to store the graph edges and DSU data.

#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>

// represents a weighted edge in the graph
struct Edge {
  int u, v, weight;
};

// dsu (disjoint set union) or union-find data structure
struct DSU {
  std::vector<int> parent;
  DSU(int n) {
    parent.resize(n);
    std::iota(parent.begin(), parent.end(), 0); // initialize each node as its own parent
  }

  // find the representative (root) of the set containing element i
  int find(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i]); // path compression
  }

  // union of two sets
  void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
      parent[root_i] = root_j;
    }
  }
};

int main() {
  int V, E;
  std::cout << "enter the number of vertices and edges: ";
  std::cin >> V >> E;

  std::vector<Edge> edges(E);
  std::cout << "enter the edges (u, v, weight):" << std::endl;
  for (int i = 0; i < E; ++i) {
    std::cin >> edges[i].u >> edges[i].v >> edges[i].weight;
  }

  // sort edges by weight in non-decreasing order
  std::sort(edges.begin(), edges.end(),
            [](const Edge &a, const Edge &b) { return a.weight < b.weight; });

  DSU dsu(V);
  std::vector<Edge> mst_edges;
  int mst_weight = 0;

  for (const auto &edge : edges) {
    // if including this edge does not form a cycle
    if (dsu.find(edge.u) != dsu.find(edge.v)) {
      dsu.unite(edge.u, edge.v);
      mst_edges.push_back(edge);
      mst_weight += edge.weight;
      // stop when we have V-1 edges in the MST
      if (mst_edges.size() == V - 1) {
        break;
      }
    }
  }

  if (mst_edges.size() != V - 1) {
    std::cout << "ehe graph is not connected, mst not possible." << std::endl;
  } else {
    std::cout << "\nminimum spanning tree (kruskal's algorithm):" << std::endl;
    for (const auto &edge : mst_edges) {
      std::cout << "edge: " << edge.u << " - " << edge.v
                << " | weight: " << edge.weight << std::endl;
    }
    std::cout << "total mst weight: " << mst_weight << std::endl;
  }

  return 0;
}