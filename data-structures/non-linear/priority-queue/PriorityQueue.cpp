#include "../trees/binary-tree/heap/Heap.cpp"

class PriorityQueue {
  Heap heap;

public:
  PriorityQueue() = default;

  void insertItem(int key) { heap.insertElement(key); }

  int removeTop() {
    if (heap.empty()) {
      return -1;
    }

    return heap.removeMin();
  }

  int topKey() {
    if (heap.empty()) {
      return -1;
    }

    return heap.getRoot();
  }

  bool empty() { return heap.empty(); }

  int size() { return heap.size(); }
};
