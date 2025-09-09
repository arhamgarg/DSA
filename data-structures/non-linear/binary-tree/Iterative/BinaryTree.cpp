#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

void pre_order(Node* root) {
    if (!root) return;
    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* node = st.top();
        st.pop();
        cout << node->data << " ";

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
}

void in_order(Node* root) {
    stack<Node*> st;
    Node* current = root;

    while (!st.empty() || current) {
        if (current) {
            st.push(current);
            current = current->left;
        } else {
            current = st.top();
            st.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
}

void post_order(Node* root) {
    stack<Node*> st;
    Node* lastVisited = nullptr;
    Node* current = root;

    while (!st.empty() || current) {
        if (current) {
            st.push(current);
            current = current->left;
        } else {
            Node* peek = st.top();
            if (peek->right && lastVisited != peek->right) {
                current = peek->right;
            } else {
                cout << peek->data << " ";
                lastVisited = peek;
                st.pop();
            }
        }
    }
}

void level_order(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

