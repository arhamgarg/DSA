#include <iostream>
using namespace std;

class CircularQueue {
  int *arr;
  int capacity, currSize;
  int f, b;

public:
  CircularQueue(int size) {
    capacity = size;
    arr = new int[capacity];
    currSize = 0;
    f = 0;
    b = -1;
  }

  void push(int value) {
    if (currSize == capacity) {
      cout << "Circular Queue is full!\n";
      return;
    }

    b = (b + 1) % capacity;
    arr[b] = value;
    currSize++;
  }

  void pop() {
    if (empty()) {
      cout << "Circular Queue is empty!\n";
      return;
    }

    f = (f + 1) % capacity;
    currSize--;
  }

  int front() {
    if (empty()) {
      cout << "Circular Queue is empty!\n";
      return -1;
    }

    return arr[f];
  }

  bool empty() { return currSize == 0; }

  int size() { return currSize; }
};
