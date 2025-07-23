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
  int length;

public:
  Stack() {
    head = nullptr;
    length = 0;
  }

  void push(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = newNode;
      length++;
      return;
    }

    newNode->next = head;
    head = newNode;
    length++;
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
    length--;
  }

  int top() { return head->data; }

  bool empty() { return length == 0; }

  int size() { return length; }
};
