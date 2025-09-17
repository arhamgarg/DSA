#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
  vector<int> heap;

  int parent(int i) { return (i - 1) / 2; }
  int leftChild(int i) { return 2 * i + 1; }
  int rightChild(int i) { return 2 * i + 2; }

  void upHeap(int i) {
    while (i > 0 && heap[i] < heap[parent(i)]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }
  }

  void downHeap(int i) {
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < heap.size() && heap[l] < heap[smallest]) {
      smallest = l;
    }

    if (r < heap.size() && heap[r] < heap[smallest]) {
      smallest = r;
    }

    if (smallest != i) {
      swap(heap[i], heap[smallest]);
      downHeap(smallest);
    }
  }

public:
  void insert(int key) {
    heap.push_back(key);
    upHeap(heap.size() - 1);
  }

  int getMin() {
    if (empty()) {
      cout << "Heap is empty!\n";
      return -1;
    }

    return heap[0];
  }

  int extractMin() {
    if (empty()) {
      cout << "Heap is empty!\n";
      return -1;
    }

    int root = heap[0];

    heap[0] = heap.back();
    heap.pop_back();

    if (!empty()) {
      downHeap(0);
    }

    return root;
  }

  void buildHeap(vector<int> &arr) {
    heap = arr;

    for (int i = parent(heap.size() - 1); i >= 0; i--) {
      downHeap(i);
    }
  }

  void printHeap() {
    for (int x : heap) {
      cout << x << " ";
    }

    cout << "\n";
  }

  bool empty() { return heap.empty(); }

  int size() { return heap.size(); }
};
