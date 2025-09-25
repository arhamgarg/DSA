#include <iostream>
#include <vector>
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

Node *insert(Node *root, int value) {
  if (root == nullptr) {
    return new Node(value);
  }

  if (value < root->data) {
    root->left = insert(root->left, value);
  } else {
    root->right = insert(root->right, value);
  }

  return root;
}

Node *buildBST(vector<int> &vec) {
  Node *root = nullptr;

  for (int val : vec) {
    root = insert(root, val);
  }

  return root;
}

void inorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

bool search(Node *root, int key) {
  if (root == nullptr) {
    return false;
  }

  if (root->data == key) {
    return true;
  }

  if (root->data > key) {
    return search(root->left, key);
  } else {
    return search(root->right, key);
  }
}

Node *getInorderSuccessor(Node *root) {
  while (root != nullptr && root->left != nullptr) {
    root = root->left;
  }

  return root;
}

Node *deleteNode(Node *root, int key) {
  if (root == nullptr) {
    return nullptr;
  }

  if (root->data > key) {
    root->left = deleteNode(root->left, key);
  } else if (root->data < key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == nullptr) {
      Node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == nullptr) {
      Node *temp = root->left;
      delete root;
      return temp;
    } else {
      Node *IS = getInorderSuccessor(root->right);
      root->data = IS->data;
      root->right = deleteNode(root->right, IS->data);
    }
  }

  return root;
}
