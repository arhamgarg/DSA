import { TreeNode } from "../../node/TreeNode";

function preOrderTraversal(root: TreeNode | null): void {
  if (root == null) return;

  let stack: Array<TreeNode> = new Array();
  let tempNode: TreeNode;
  stack.push(root);

  while (stack.length != 0) {
    //@ts-expect-error empty array pop returns undefined but that is already checked in the while loop
    tempNode = stack.pop();

    console.log(`${tempNode.getValue()}`);
    if (tempNode.getRight() != null) {
      //@ts-ignore checking has been done for right being null
      stack.push(tempNode.getRight());
    }

    if (tempNode.getLeft() != null) {
      //@ts-ignore
      stack.push(tempNode.getRight());
    }
  }
}

function inOrderTraversal(root: TreeNode | null): void {
  if (root == null) return;

  let stack: Array<TreeNode> = new Array();
  let node: TreeNode | null = root;

  while (node != null || stack.length != 0) {
    if (node != null) {
      stack.push(node);
      node = node.getLeft();
    } else {
      //@ts-expect-error
      node = stack.pop();
      console.log(`${node?.getValue()}`);
      //@ts-expect-error
      node = node.getRight();
    }
  }
}

function postOrderTraversal(root: TreeNode | null): void {
  let stack: Array<TreeNode> = new Array();

  let lastVisitedNode: TreeNode | null = null;
  let node: TreeNode | null = root;

  while (node != null || stack.length != 0) {
    if (node != null) {
      stack.push(node);
      node = node.getLeft();
    } else {
      let peek: TreeNode | null = stack[-1];

      if (peek.getRight() != null && lastVisitedNode != peek.getRight()) {
        node = peek.getRight();
      } else {
        console.log(`${peek.getValue()}`);
        lastVisitedNode = peek;
        stack.pop();
      }
    }
  }
}
