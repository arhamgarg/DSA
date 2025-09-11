#include <stdlib.h>

typedef struct Node {
  int value;
  struct Node *nextNode;
} Node;

Node *createNode(int val, Node *next) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node) {
    node->value = val;
    node->nextNode = next;
  }
  return node;
}

int getValue(const Node *node) { return node->value; }

Node *getNextNode(const Node *node) { return node->nextNode; }

void setNextNode(Node *node, Node *next) { node->nextNode = next; }