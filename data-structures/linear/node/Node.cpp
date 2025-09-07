class Node {
public:
  int val;
  Node *next;

  Node(int val, Node *next = nullptr) {
    this->val = val;
    this->next = next;
  }

  int getValue() { return val; }

  Node *getNext() { return next; }

  void setNext(Node *next) { this->next = next; }
};
