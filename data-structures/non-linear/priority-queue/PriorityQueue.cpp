#include "../binary-tree/heap/max-heap/MaxHeap.cpp"
#include "../binary-tree/heap/min-heap/MinHeap.cpp"

class PriorityQueue {
  bool isMinQueue;
  MinHeap minHeap;
  MaxHeap maxHeap;

public:
  PriorityQueue(bool type = true) { isMinQueue = type; }

  void insertItem(int key) {
    if (isMinQueue) {
      minHeap.insert(key);
    } else {
      maxHeap.insert(key);
    }
  }

  int removeTop() {
    return isMinQueue ? minHeap.extractMin() : maxHeap.extractMax();
  }

  int topKey() { return isMinQueue ? minHeap.getMin() : maxHeap.getMax(); }

  void buildHeap(vector<int> &arr) {
    if (isMinQueue) {
      minHeap.buildHeap(arr);
    } else {
      maxHeap.buildHeap(arr);
    }
  }

  void print() {
    if (isMinQueue) {
      minHeap.printHeap();
    } else {
      maxHeap.printHeap();
    }
  }

  bool empty() { return isMinQueue ? minHeap.empty() : maxHeap.empty(); }

  int size() { return isMinQueue ? minHeap.size() : maxHeap.size(); }
};
