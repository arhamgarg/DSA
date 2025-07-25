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

static int index = -1;

Node *buildTree(vector<int> preorder) {
  index++;

  if (preorder[index] == -1) {
    return nullptr;
  }

  Node *root = new Node(preorder[index]);
  root->left = buildTree(preorder);
  root->right = buildTree(preorder);

  return root;
}

void preorder(Node *root) {
  if (root == nullptr) {
    return;
  }

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root) {
  if (root == nullptr) {
    return;
  }

  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

void postorder(Node *root) {
  if (root == nullptr) {
    return;
  }

  postorder(root->left);
  postorder(root->right);
  cout << root->data << " ";
}
