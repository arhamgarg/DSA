#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int value) {
    data = value;
    left = right = nullptr;
  }
};

void preorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }

  stack<Node *> s;

  s.push(root);

  while (!s.empty()) {
    Node *node = s.top();

    s.pop();
    cout << node->data << " ";

    if (node->right) {
      s.push(node->right);
    }

    if (node->left) {
      s.push(node->left);
    }
  }
}

void inorderTraversal(Node *root) {
  stack<Node *> s;

  Node *node = root;

  while (node != nullptr || !s.empty()) {
    if (node != nullptr) {
      s.push(node);
      node = node->left;
    } else {
      node = s.top();
      s.pop();
      cout << node->data << " ";
      node = node->right;
    }
  }
}

void postorderTraversal(Node *root) {
  stack<Node *> s;

  Node *lastVisited = nullptr;
  Node *node = root;

  while (node != nullptr || !s.empty()) {
    if (node != nullptr) {
      s.push(node);
      node = node->left;
    } else {
      Node *peek = s.top();

      if (peek->right && lastVisited != peek->right) {
        node = peek->right;
      } else {
        cout << peek->data << " ";
        lastVisited = peek;
        s.pop();
      }
    }
  }
}

void levelorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }

  queue<Node *> q;

  q.push(root);

  while (!q.empty()) {
    Node *node = q.front();

    q.pop();
    cout << node->data << " ";

    if (node->left) {
      q.push(node->left);
    }

    if (node->right) {
      q.push(node->right);
    }
  }
}
