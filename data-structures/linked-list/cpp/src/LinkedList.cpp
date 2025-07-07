#include "../include/list.h"
using namespace std;

Node::Node(int val) {
  data = val;
  next = nullptr;
}

List::List() { head = tail = nullptr; }

void List::push_front(int val) {
  Node *newNode = new Node(val);

  if (head == nullptr) {
    head = tail = newNode;
    return;
  }

  newNode->next = head;
  head = newNode;
}

void List::push_back(int val) {
  Node *newNode = new Node(val);

  if (head == nullptr) {
    head = tail = newNode;
    return;
  }

  tail->next = newNode;
  tail = newNode;
}

void List::pop_front() {
  if (head == nullptr) {
    cout << "Linked List is empty!\n";
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

void List::pop_back() {
  if (head == nullptr) {
    cout << "Linked List is empty!\n";
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

void List::insert(int val, int pos) {
  if (pos < 0) {
    cout << "Invalid position!\n";
    return;
  } else if (pos == 0) {
    push_front(val);
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

  Node *newNode = new Node(val);
  newNode->next = temp->next;
  temp->next = newNode;

  if (newNode->next == nullptr) {
    tail = newNode;
  }
}

void List::print() {
  Node *temp = head;

  while (temp != nullptr) {
    cout << temp->data << " -> ";
    temp = temp->next;
  }

  cout << "NULL\n";
}

int List::search(int key) {
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
