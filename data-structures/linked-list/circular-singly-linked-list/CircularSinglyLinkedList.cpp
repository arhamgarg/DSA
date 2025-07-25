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

class CircularSinglyLinkedList {
  Node *head;
  Node *tail;

public:
  CircularSinglyLinkedList() { head = tail = nullptr; }

  void insertAtHead(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      tail->next = head;
    }

    newNode->next = head;
    head = newNode;
    tail->next = head;
  }

  void insertAtTail(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      tail->next = head;
    }

    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
  }

  void deleteAtHead() {
    if (head == nullptr) {
      return;
    } else if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Node *temp = head;

      head = head->next;
      tail->next = head;
      temp->next = nullptr;
      delete temp;
    }
  }

  void deleteAtTail() {
    if (head == nullptr) {
      return;
    } else if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Node *temp = tail;
      Node *prev = head;

      while (prev->next != tail) {
        prev = prev->next;
      }

      tail = prev;
      tail->next = head;
      temp->next = nullptr;
      delete temp;
    }
  }

  void print() {
    if (head == nullptr) {
      return;
    }

    cout << head->data << " -> ";
    Node *temp = head->next;

    while (temp != head) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }

    cout << temp->data << "\n";
  }
};
