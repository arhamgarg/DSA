import { TreeNode } from "../node/TreeNode";

function insert(root: TreeNode | null, value: number): TreeNode {
  if (root == null) {
    return new TreeNode(value);
  }

  if (value < root.getValue()) {
    root.setLeft(insert(root.getLeft(), value));
  } else {
    root.setRight(insert(root.getRight(), value));
  }

  return root;
}

function buildTree(preOrderArray: Array<number>): TreeNode | null {
  let node: TreeNode | null = null;

  for (const value of preOrderArray) {
    node = insert(node, value);
  }

  return node;
}

function preOrderTraversal(root: TreeNode | null): void {
  if (root == null) {
    return;
  }

  console.log(`${root.getValue()}`);
  preOrderTraversal(root.getLeft());
  preOrderTraversal(root.getRight());
}

function inOrderTraversal(root: TreeNode | null): void {
  if (root == null) {
    return;
  }

  inOrderTraversal(root.getLeft());
  console.log(`${root.getValue()}`);
  inOrderTraversal(root.getRight());
}

function postOrderTraversal(root: TreeNode | null): void {
  if (root == null) {
    return;
  }

  postOrderTraversal(root.getLeft());
  postOrderTraversal(root.getRight());
  console.log(`${root.getValue()}`);
}

function search(root: TreeNode | null, value: number): boolean {
  if (root == null) {
    return false;
  }

  if (root.getValue() == value) {
    return true;
  }

  if (root.getValue() < value) {
    return search(root.getLeft(), value);
  } else {
    return search(root.getRight(), value);
  }
}

function inOrderSuccessor(root: TreeNode | null): TreeNode | null {
  while (root != null && root.getLeft() != null) {
    root.setLeft(root.getLeft());
  }

  return root;
}

function deleteNode(root: TreeNode | null, value: number): TreeNode | null {
  if (root == null) {
    return null;
  }

  if (root.getValue() > value) {
    root.setLeft(deleteNode(root.getLeft(), value));
  } else if (root.getValue() < value) {
    root.setRight(deleteNode(root.getRight(), value));
  } else {
    if (root.getLeft() == null) {
      return root.getRight();
    } else if (root.getRight() == null) {
      return root.getLeft();
    }

    const successor: TreeNode | null = inOrderSuccessor(root.getRight());
    //@ts-expect-error There is no possible way to get null in inOrderSuccessor
    root.setValue(successor.getValue());
    //@ts-expect-error There is no possible way to get null in inOrderSuccessor
    root.setRight(deleteNode(root.getRight(), successor?.getValue()));
  }

  return root;
}
