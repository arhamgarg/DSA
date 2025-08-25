#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node *prev;

  Node(int value) {
    data = value;
    next = prev = nullptr;
  }
};

class Deque {
  Node *head;
  Node *tail;
  int length;

public:
  Deque() {
    head = tail = nullptr;
    length = 0;
  }

  void push_front(int value) {
    Node *newNode = new Node(value);

    if (empty()) {
      head = tail = newNode;
    } else {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }

    length++;
  }

  void push_back(int value) {
    Node *newNode = new Node(value);

    if (empty()) {
      head = tail = newNode;
    } else {
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
    }

    length++;
  }

  void pop_front() {
    if (empty()) {
      cout << "Deque is empty!\n";
      return;
    }

    Node *temp = head;

    head = head->next;

    if (head != nullptr) {
      head->prev = nullptr;
    } else {
      tail = nullptr;
    }

    delete temp;
    length--;
  }

  void pop_back() {
    if (empty()) {
      cout << "Deque is empty!\n";
      return;
    }

    Node *temp = tail;

    tail = tail->prev;

    if (tail != nullptr) {
      tail->next = nullptr;
    } else {
      head = nullptr;
    }

    delete temp;
    length--;
  }

  int front() {
    if (empty()) {
      cout << "Deque is empty!\n";
      return -1;
    }

    return head->data;
  }

  int back() {
    if (empty()) {
      cout << "Deque is empty!\n";
      return -1;
    }
    
    return tail->data;
  }

  bool empty() { return length == 0; }

  int size() { return length; }
};
