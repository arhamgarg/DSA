class TreeNode {
  int value;
  TreeNode *right;
  TreeNode *left;

public:
  TreeNode(int value, TreeNode *right = nullptr, TreeNode *left = nullptr)
      : value(value), right(right), left(left) {}

  int getValue() { return value; }

  TreeNode *getRight() { return right; }

  TreeNode *getLeft() { return left; }

  void setValue(int value) { this->value = value; }

  void setRight(TreeNode *node) { right = node; }

  void setLeft(TreeNode *node) { left = node; }
};
