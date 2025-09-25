#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int value) {
    data = value;
    next = nullptr;
  }
};

class Queue {
  Node *head;
  Node *tail;
  int length;

public:
  Queue() {
    head = tail = nullptr;
    length = 0;
  }

  void push(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      length++;
      return;
    }

    tail->next = newNode;
    tail = newNode;
    length++;
  }

  void pop() {
    if (head == nullptr) {
      cout << "Queue is empty!\n";
      return;
    }

    Node *temp = head;
    
    head = head->next;
    temp->next = nullptr;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }

    length--;
  }

  int front() { return head->data; }

  bool empty() { return length == 0; }

  int size() { return length; }
};
