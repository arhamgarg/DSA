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

class SinglyLinkedList {
  Node *head;
  Node *tail;

public:
  SinglyLinkedList() { head = tail = nullptr; }

  void push_front(int value) {
    Node *newNode = new Node(value);

    newNode->next = head;
    head = newNode;
  }

  void push_back(int value) {
    Node *newNode = new Node(value);

    if (head == nullptr) {
      head = tail = newNode;
      return;
    }

    tail->next = newNode;
    tail = newNode;
  }

  void pop_front() {
    if (head == nullptr) {
      cout << "Singly Linked List is empty!\n";
      return;
    }

    Node *temp = head;

    head = head->next;
    temp->next = nullptr;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }
  }

  void pop_back() {
    if (head == nullptr) {
      cout << "Singly Linked List is empty!\n";
      return;
    }

    if (head == tail) {
      delete head;
      head = tail = nullptr;
      return;
    }

    Node *temp = head;

    while (temp->next != tail) {
      temp = temp->next;
    }

    temp->next = nullptr;
    delete tail;
    tail = temp;
  }

  void insert(int value, int pos) {
    if (pos < 0) {
      cout << "Invalid position!\n";
      return;
    } else if (pos == 0) {
      push_front(value);
      return;
    }

    Node *temp = head;

    for (int i = 0; i < pos - 1; ++i) {
      if (temp == nullptr) {
        cout << "Invalid position!\n";
        return;
      }

      temp = temp->next;
    }

    Node *newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == nullptr) {
      tail = newNode;
    }
  }

  void print() {
    Node *temp = head;

    while (temp != nullptr) {
      cout << temp->data << " -> ";
      temp = temp->next;
    }

    cout << "NULL\n";
  }

  int search(int key) {
    Node *temp = head;
    int index = 0;

    while (temp != nullptr) {
      if (temp->data == key) {
        return index;
      }

      temp = temp->next;
      index++;
    }

    return -1;
  }
};
