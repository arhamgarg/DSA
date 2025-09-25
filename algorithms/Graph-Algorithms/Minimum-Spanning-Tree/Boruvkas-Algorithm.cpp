// boruvka's algorithm for minimum spanning tree (MST)
//
// this algorithm finds the mst of a connected, undirected, and weighted graph.
// it is a parallelizable algorithm that works in stages. in each stage, it
// finds the cheapest edge outgoing from each component and adds these edges to
// the mst. the components are then merged, and the process repeats until only
// one component remains.
//
// time complexity: O(E log V), as there are at most log V stages, and each
// stage takes O(E) time.
// space complexity: O(V + E) to store the graph, components, and cheapest edges.

#include <iostream>
#include <numeric>
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
    std::iota(parent.begin(), parent.end(), 0);
  }

  int find(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i]);
  }

  void unite(int i, int j) { // union of two sets
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

  DSU dsu(V);
  std::vector<Edge> mst_edges;
  int mst_weight = 0;
  int num_components = V;

  while (num_components > 1) {
    // cheapest[i] stores the index of the cheapest edge for a component
    // initialize with -1.
    std::vector<int> cheapest(V, -1);

    // for each edge, find the components of its vertices. if they are in
    // different components, check if this edge is the cheapest outgoing
    // edge for either component.
    for (int i = 0; i < E; ++i) {
      int root_u = dsu.find(edges[i].u);
      int root_v = dsu.find(edges[i].v);

      if (root_u == root_v)
        continue;

      if (cheapest[root_u] == -1 ||
          edges[i].weight < edges[cheapest[root_u]].weight) {
        cheapest[root_u] = i;
      }
      if (cheapest[root_v] == -1 ||
          edges[i].weight < edges[cheapest[root_v]].weight) {
        cheapest[root_v] = i;
      }
    }

    // add the cheapest edges to the mst, merging components.
    for (int i = 0; i < V; ++i) {
      if (cheapest[i] != -1) {
        const auto &edge = edges[cheapest[i]];
        int root_u = dsu.find(edge.u);
        int root_v = dsu.find(edge.v);

        if (root_u != root_v) {
          dsu.unite(root_u, root_v);
          mst_edges.push_back(edge);
          mst_weight += edge.weight;
          num_components--;
        }
      }
    }
  }

  std::cout << "\nminimum spanning tree (boruvka's algorithm):" << std::endl;
  for (const auto &edge : mst_edges) {
    std::cout << "edge: " << edge.u << " - " << edge.v
              << " | weight: " << edge.weight << std::endl;
  }
  std::cout << "total mst weight: " << mst_weight << std::endl;

  return 0;
}