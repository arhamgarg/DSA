//prims algo for minimum spanning tree (MST)
//
//this algo will find the mst of a connected , undirected, and weighted graph.

//it is a greedy algorithm that starts from an arbitrary vertex and grows the mst by 
//adding the cheapest possible connection from thee tree to another vertex at each step.

//this is implemented using a priority queue(min-heap) for efficiently selecting the minimum weight edge to add.

// time complexity: O(E log V) with a binary heap-based priority queue.
// space complexity: O(V + E) for the adjacency list, priority queue, and visited array.

#include <iostream>
#include <queue>
#include <vector>

// represents a pair of (weight, vertex) for the priority queue
using EdgePair = std::pair<int, int>;

// represents a pair of (neighbor, weight) for the adjacency list
using AdjPair = std::pair<int, int>;

int main() {
  int V, E;
  std::cout << "rnter the number of vertices and edges: ";
  std::cin >> V >> E;

  std::vector<std::vector<AdjPair>> adj(V);
  std::cout << "rnter the edges (u, v, weight):" << std::endl;
  for (int i = 0; i < E; ++i) {
    int u, v, weight;
    std::cin >> u >> v >> weight;
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); 
  }

  // priority queue to store pairs of (weight, vertex).
  // we use std::greater to make it a min-heap.
  std::priority_queue<EdgePair, std::vector<EdgePair>, std::greater<EdgePair>>
      pq;

  std::vector<bool> in_mst(V, false); // to track vertices included in mst
  std::vector<std::pair<int, int>>
      mst_edges; // to store edges of the mst {u, v}
  std::vector<int> parent(V, -1); // to reconstruct the mst edges
  int mst_weight = 0;

  // start with vertex 0
  int start_vertex = 0;
  pq.push({0, start_vertex}); // {weight, vertex}

  while (!pq.empty()) {
    int u = pq.top().second;
    int weight = pq.top().first;
    pq.pop();

    // if vertex u is already in mst, skip it
    if (in_mst[u]) {
      continue;
    }

    // include vertex u in mst
    in_mst[u] = true;
    mst_weight += weight;
    if (parent[u] != -1) {
      mst_edges.push_back({parent[u], u});
    }

    // explore neighbors of u
    for (const auto &edge : adj[u]) {
      int v = edge.first;
      int edge_weight = edge.second;
      if (!in_mst[v]) {
        pq.push({edge_weight, v});
        parent[v] = u; // keep track of the edge that connects v
      }
    }
  }

  std::cout << "\nminimum spanning tree (prim's algo):" << std::endl;
  for (const auto &edge : mst_edges) {
    std::cout << "edge: " << edge.first << " - " << edge.second << std::endl;
  }
  std::cout << "total mst weight: " << mst_weight << std::endl;

  return 0;
}