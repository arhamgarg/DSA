#include <vector>
using namespace std;

class Heap {
  vector<int> elements;

  int parent(int i) { return (i - 1) / 2; }
  int leftChild(int i) { return 2 * i + 1; }
  int rightChild(int i) { return 2 * i + 2; }

public:
  void insertElement(int e) {
    elements.push_back(e);
    int i = elements.size() - 1;

    while (i > 0 && elements[i] < elements[parent(i)]) {
      swap(elements[i], elements[parent(i)]);
      i = parent(i);
    }
  }

  int removeMin() {
    if (elements.empty()) {
      return -1;
    }

    int root = elements[0];
    elements[0] = elements.back();
    elements.pop_back();

    if (!elements.empty()) {
      heapify(0);
    }

    return root;
  }

  void heapify(int i) {
    int smallest = i;
    int l = leftChild(i);
    int r = rightChild(i);

    if (l < elements.size() && elements[l] < elements[smallest]) {
      smallest = l;
    }

    if (r < elements.size() && elements[r] < elements[smallest]) {
      smallest = r;
    }

    if (smallest != i) {
      swap(elements[i], elements[smallest]);
      heapify(smallest);
    }
  }

  int getRoot() { return elements[0]; }

  bool empty() { return elements.empty(); }

  int size() { return elements.size(); }
};
