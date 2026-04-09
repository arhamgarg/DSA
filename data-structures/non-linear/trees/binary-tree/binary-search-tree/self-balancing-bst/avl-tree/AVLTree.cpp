#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;
  int height;

  Node(int value) {
    data = value;
    left = right = nullptr;
    height = 1;
  }
};

class AVLTree {
  Node *root;

  int height(Node *node) { return node ? node->height : 0; }

  int balanceFactor(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
  }

  Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
  }

  Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
  }

  Node *insert(Node *node, int value) {
    if (node == nullptr) {
      return new Node(value);
    }

    if (value < node->data) {
      node->left = insert(node->left, value);
    } else if (value > node->data) {
      node->right = insert(node->right, value);
    } else {
      return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && value < node->left->data) {
      return rightRotate(node);
    }

    if (balance < -1 && value > node->right->data) {
      return leftRotate(node);
    }

    if (balance > 1 && value > node->left->data) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }

    if (balance < -1 && value < node->right->data) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }

    return node;
  }

public:
  AVLTree() { root = nullptr; }

  void insert(int value) { root = insert(root, value); }

  void inorderTraversal(Node *root) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
  }
};
