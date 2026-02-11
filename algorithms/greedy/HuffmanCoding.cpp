#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  char ch;
  int freq;
  Node *left;
  Node *right;

  Node(char ch, int freq) {
    this->ch = ch;
    this->freq = freq;
    left = nullptr;
    right = nullptr;
  }

  Node(char ch, int freq, Node *left, Node *right) {
    this->ch = ch;
    this->freq = freq;
    this->left = left;
    this->right = right;
  }
};

struct compare {
  bool operator()(Node *l, Node *r) { return l->freq > r->freq; }
};

void printCodes(Node *root, string str,
                unordered_map<char, string> &huffmanCode) {
  if (root == nullptr) {
    return;
  }

  if (!root->left && !root->right) {
    huffmanCode[root->ch] = str;
  }

  printCodes(root->left, str + "0", huffmanCode);
  printCodes(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text) {
  unordered_map<char, int> freq;

  for (char ch : text) {
    freq[ch]++;
  }

  priority_queue<Node *, vector<Node *>, compare> pq;

  for (auto pair : freq) {
    pq.push(new Node(pair.first, pair.second));
  }

  while (pq.size() != 1) {
    Node *left = pq.top();
    pq.pop();
    Node *right = pq.top();
    pq.pop();

    int sum = left->freq + right->freq;

    pq.push(new Node('\0', sum, left, right));
  }

  Node *root = pq.top();
  unordered_map<char, string> huffmanCode;

  printCodes(root, "", huffmanCode);
  cout << "Huffman Codes:\n";

  for (auto pair : huffmanCode) {
    cout << pair.first << " " << pair.second << "\n";
  }

  cout << "\nOriginal string:\n" << text << "\n";

  string str = "";

  for (char ch : text) {
    str += huffmanCode[ch];
  }

  cout << "\nEncoded string:\n" << str << "\n";

  auto decode = [&](string str) {
    cout << "\nDecoded string:\n";

    Node *curr = root;

    for (char bit : str) {
      if (bit == '0') {
        curr = curr->left;
      } else {
        curr = curr->right;
      }

      if (!curr->left && !curr->right) {
        cout << curr->ch;
        curr = root;
      }
    }

    cout << "\n";
  };

  decode(str);
}
