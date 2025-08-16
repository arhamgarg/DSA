import java.util.LinkedList;
import java.util.Queue;

class Node {
  int data;
  Node left;
  Node right;

  public Node(int data) {
    this.data = data;
    this.right = null;
    this.left = null;
  }
}

public class BinaryTree {
  int idx = -1;

  Node buildTree(int nodes[]) {
    idx++;
    if (nodes[idx] == -1) {
      return null;
    }

    Node newNode = new Node(nodes[idx]);
    newNode.left = buildTree(nodes);
    newNode.right = buildTree(nodes);

    return newNode;
  }

  void preorder(Node root) {
    if (root == null) {
      return;
    }

    System.out.print(root.data + " ");
    preorder(root.left);
    preorder(root.right);
  }

  void inorder(Node root) {
    if (root == null) {
      return;
    }

    inorder(root.left);
    System.out.print(root.data + " ");
    inorder(root.right);
  }

  void postorder(Node root) {
    if (root == null) {
      return;
    }

    postorder(root.left);
    postorder(root.right);
    System.out.print(root.data + " ");
  }

  void levelorder(Node root) {
    if (root == null) {
      return;
    }

    Queue<Node> q = new LinkedList<>();
    q.add(root);
    q.add(null);

    while (!q.isEmpty()) {
      Node currNode = q.remove();

      if (currNode == null) {
        System.out.println();

        if (q.isEmpty()) {
          break;
        } else {
          q.add(null);
        }
      } else {
        System.out.print(currNode.data + " ");
        if (currNode.left != null) {
          q.add(currNode.left);
        }
        if (currNode.right != null) {
          q.add(currNode.right);
        }
      }
    }
  }
}