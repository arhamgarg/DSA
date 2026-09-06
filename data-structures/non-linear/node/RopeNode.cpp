class RopeNode {
  int value;
  RopeNode *nextNode;
  RopeNode *previousNode;

public:
  RopeNode(int value, RopeNode *nextNode = nullptr,
           RopeNode *previousNode = nullptr)
      : value(value), nextNode(nextNode), previousNode(previousNode) {}

  int getValue() { return value; }

  RopeNode *getNextNode() { return nextNode; }

  RopeNode *getPreviousNode() { return previousNode; }

  void setNextNode(RopeNode *node) { nextNode = node; }

  void setPreviousNode(RopeNode *node) { previousNode = node; }
};
