import { TreeNode } from "../../node/TreeNode";

let index: number = -1;

function buildTree(preOrderArray: Array<number>): TreeNode | null {
  index++;

  if (index >= preOrderArray.length || preOrderArray[index] == -1) {
    return null;
  }

  let root: TreeNode = new TreeNode(preOrderArray[index]);
  root.setLeft(buildTree(preOrderArray));
  root.setRight(buildTree(preOrderArray));

  return root;
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

function levelOrderTraversal(root: TreeNode | null): void {
  if (root == null) {
    return;
  }

  let queue: Array<TreeNode | null> = new Array();
  let temp: TreeNode | null | undefined; // as array.shift() can return undefined
  queue.push(root);
  queue.push(null);

  while (queue.length != 0) {
    temp = queue.shift();

    if (temp == undefined) {
      continue;
    }

    if (temp == null) {
      if (queue.length != 0) {
        queue.push(null);
      }
    } else {
      console.log(`${temp.getValue()}`);

      if (temp.getLeft() != null) {
        queue.push(temp.getLeft());
      }

      if (temp.getRight() != null) {
        queue.push(temp.getRight());
      }
    }
  }
}

export {
  buildTree,
  inOrderTraversal,
  levelOrderTraversal,
  postOrderTraversal,
  preOrderTraversal,
};
