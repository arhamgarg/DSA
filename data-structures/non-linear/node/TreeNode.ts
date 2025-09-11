class TreeNode {
  private value: number;
  private right: TreeNode | null;
  private left: TreeNode | null;

  constructor(
    value: number,
    right: TreeNode | null = null,
    left: TreeNode | null = null
  ) {
    this.value = value;
    this.right = right;
    this.left = left;
  }

  getValue(): number {
    return this.value;
  }

  getRight(): TreeNode | null {
    return this.right;
  }

  getLeft(): TreeNode | null {
    return this.left;
  }

  setValue(value: number): void {
    this.value = value;
  }

  setRight(node: TreeNode | null): void {
    this.right = node;
  }

  setLeft(node: TreeNode | null): void {
    this.left = node;
  }
}

export { TreeNode };
