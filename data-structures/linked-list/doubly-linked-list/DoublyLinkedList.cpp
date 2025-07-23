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

class DoublyLinkedList {
  Node *head;
  Node *tail;

public:
  DoublyLinkedList() { head = tail = nullptr; }

  void push_front(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }

  void push_back(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }

  void pop_front() {
    if (head == nullptr) {
      cout << "Doubly Linked List is empty!\n";
      return;
    }

    Node *temp = head;

    head = head->next;

    if (head != nullptr) {
      head->prev = nullptr;
    }

    temp->next = nullptr;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }
  }

  void pop_back() {
    if (head == nullptr) {
      cout << "Doubly Linked List is empty!\n";
      return;
    }

    if (head == tail) {
      delete head;
      head = tail = nullptr;
      return;
    }

    Node *temp = tail;
    
    tail = tail->prev;

    if (tail != nullptr) {
      tail->next = nullptr;
    }

    temp->prev = nullptr;
    delete temp;
  }

  void print() {
    Node *temp = head;

    while (temp != nullptr) {
      cout << temp->data << " <-> ";
      temp = temp->next;
    }

    cout << "NULL\n";
  }
};
