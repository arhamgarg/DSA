#include <iostream>
#include <queue>
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

Node *buildBT(vector<int> preorder) {
  index++;

  if (preorder[index] == -1) {
    return nullptr;
  }

  Node *root = new Node(preorder[index]);
  root->left = buildBT(preorder);
  root->right = buildBT(preorder);

  return root;
}

void preorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }

  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
  if (root == nullptr) {
    return;
  }

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}

void levelorderTraversal(Node *root) {
  queue<Node *> q;

  q.push(root);
  q.push(nullptr);

  while (q.size() > 0) {
    Node *temp = q.front();

    q.pop();

    if (temp == nullptr) {
      if (!q.empty()) {
        cout << "\n";
        q.push(nullptr);
        continue;
      } else {
        break;
      }
    }

    cout << temp->data << " ";

    if (temp->left != nullptr) {
      q.push(temp->left);
    }

    if (temp->right != nullptr) {
      q.push(temp->right);
    }
  }

  cout << "\n";
}
