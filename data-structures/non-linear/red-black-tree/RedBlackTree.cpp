#include <iostream>
using namespace std;

class Node {
public:
  int data;
  string color;
  Node *left, *right, *parent;

  Node(int value) {
    data = value;
    color = "RED";
    left = right = parent = nullptr;
  }
};

class RedBlackTree {
  Node *root;
  Node *NIL;

  void rotateLeft(Node *x) {
    Node *y = x->right;

    x->right = y->left;

    if (y->left != NIL) {
      y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
      root = y;
    } else if (x == x->parent->left) {
      x->parent->left = y;
    } else {
      x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
  }

  void rotateRight(Node *x) {
    Node *y = x->left;

    x->left = y->right;

    if (y->right != NIL) {
      y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == nullptr) {
      root = y;
    } else if (x == x->parent->right) {
      x->parent->right = y;
    } else {
      x->parent->left = y;
    }

    y->right = x;
    x->parent = y;
  }

  void fixInsert(Node *k) {
    while (k != root && k->parent->color == "RED") {
      if (k->parent == k->parent->parent->left) {
        Node *u = k->parent->parent->right;

        if (u->color == "RED") {
          k->parent->color = "BLACK";
          u->color = "BLACK";
          k->parent->parent->color = "RED";
          k = k->parent->parent;
        } else {
          if (k == k->parent->right) {
            k = k->parent;
            rotateLeft(k);
          }

          k->parent->color = "BLACK";
          k->parent->parent->color = "RED";
          rotateRight(k->parent->parent);
        }
      } else {
        Node *u = k->parent->parent->left;

        if (u->color == "RED") {
          k->parent->color = "BLACK";
          u->color = "BLACK";
          k->parent->parent->color = "RED";
          k = k->parent->parent;
        } else {
          if (k == k->parent->left) {
            k = k->parent;
            rotateRight(k);
          }

          k->parent->color = "BLACK";
          k->parent->parent->color = "RED";
          rotateLeft(k->parent->parent);
        }
      }
    }

    root->color = "BLACK";
  }

public:
  RedBlackTree() {
    NIL = new Node(0);
    NIL->color = "BLACK";
    NIL->left = NIL->right = NIL;
    root = NIL;
  }

  void insert(int data) {
    Node *newNode = new Node(data);

    newNode->left = NIL;
    newNode->right = NIL;

    Node *parent = nullptr;
    Node *current = root;

    while (current != NIL) {
      parent = current;

      if (newNode->data < current->data) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    newNode->parent = parent;

    if (parent == nullptr) {
      root = newNode;
    } else if (newNode->data < parent->data) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }

    if (newNode->parent == nullptr) {
      newNode->color = "BLACK";
      return;
    }

    if (newNode->parent->parent == nullptr) {
      return;
    }

    fixInsert(newNode);
  }

  void inorder(Node *node) {
    if (node != NIL) {
      inorder(node->left);
      cout << node->data << " ";
      inorder(node->right);
    }
  }

  Node *search(Node *node, int data) {
    if (node == NIL || data == node->data) {
      return node;
    }

    if (data < node->data) {
      return search(node->left, data);
    }

    return search(node->right, data);
  }
};
