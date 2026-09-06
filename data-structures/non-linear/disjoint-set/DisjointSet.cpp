#include <numeric>
#include <utility>
#include <vector>

using namespace std;

class DisjointSet {
  vector<int> parent;
  vector<int> rank;

public:
  explicit DisjointSet(int size) : parent(size), rank(size, 0) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int value) {
    if (parent[value] != value) {
      parent[value] = find(parent[value]);
    }

    return parent[value];
  }

  void unite(int first, int second) {
    first = find(first);
    second = find(second);

    if (first == second) {
      return;
    }

    if (rank[first] < rank[second]) {
      swap(first, second);
    }

    parent[second] = first;
    if (rank[first] == rank[second]) {
      rank[first]++;
    }
  }

  bool connected(int first, int second) { return find(first) == find(second); }
};
