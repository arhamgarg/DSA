class Node {
private:
  int value;
  Node *nextNode;

public:
  Node(int val, Node *next = nullptr) {
    value = val;
    nextNode = next;
  }

  int getValue() const { return value; }

  Node *getNextNode() const { return nextNode; }

  void setNextNode(Node *next) { nextNode = next; }
};
