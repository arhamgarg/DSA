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

class Stack {
  Node *head;
  int size;

public:
  Stack() {
    head = nullptr;
    size = 0;
  }

  void push(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = newNode;
      size++;
      return;
    }

    newNode->next = head;
    head = newNode;
    size++;
  }

  void pop() {
    if (head == nullptr) {
      cout << "Stack is empty!\n";
      return;
    }

    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
    size--;
  }

  int top() { return head->data; }

  bool empty() { return size == 0; }
};
