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

class CircularDoublyLinkedList {
  Node *head;
  Node *tail;

public:
  CircularDoublyLinkedList() { head = tail = nullptr; }

  void insertAtHead(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      head->next = head->prev = head;
    } else {
      newNode->next = head;
      newNode->prev = tail;
      head->prev = newNode;
      tail->next = newNode;
      head = newNode;
    }
  }

  void insertAtTail(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      head->next = head->prev = head;
    } else {
      newNode->prev = tail;
      newNode->next = head;
      tail->next = newNode;
      head->prev = newNode;
      tail = newNode;
    }
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
      head->prev = tail;
      tail->next = head;
      temp->next = temp->prev = nullptr;
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

      tail = tail->prev;
      tail->next = head;
      head->prev = tail;
      temp->next = temp->prev = nullptr;
      delete temp;
    }
  }

  void print() {
    if (head == nullptr) {
      return;
    }

    Node *temp = head;

    do {
      cout << temp->data << " <-> ";
      temp = temp->next;
    } while (temp != head);

    cout << temp->data << "\n";
  }
};
