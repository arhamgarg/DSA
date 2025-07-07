#ifndef LIST_H
#define LIST_H

#include <iostream>

class Node {
public:
  int data;
  Node *next;

  Node(int val);
};

class List {
  Node *head;
  Node *tail;

public:
  List();

  void push_front(int val);
  void push_back(int val);
  void pop_front();
  void pop_back();
  void insert(int val, int pos);
  void print();
  int search(int key);
};

#endif
