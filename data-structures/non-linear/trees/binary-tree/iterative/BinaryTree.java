import java.util.*;

class Node {
  int data;
  Node left, right;
  Node(int data) {
    this.data = data;
    this.left = this.right = null;
  }
}

public class BinaryTree {
  public static void preOrder(Node root) {
    if (root == null)
      return;
    Stack<Node> s = new Stack<>();
    s.push(root);
    while (!s.isEmpty()) {
      Node n = s.pop();
      System.out.println(n.data + " ");
      if (n.right != null)
        s.push(n.right);
      if (n.left != null)
        s.push(n.left);
    }
  }

  public static void inOrder(Node root) {
    Stack<Node> s = new Stack<>();
    Node current = root;
    while (current != null || !s.isEmpty()) {
      while (current != null) {
        s.push(current);
        current = current.left;
      }
      current = s.pop();
      System.out.println(current.data + " ");
      current = current.right;
    }
  }

  public static void postOrder(Node root) {
    Stack<Node> s = new Stack<>();
    Node prev = null;
    Node current = root;
    while (current != null || !s.isEmpty()) {
      if (current != null) {
        s.push(current);
        current = current.left;
      } else {
        Node top = s.peek();
        if (top.right != null && prev != top.right) {
          current = top.right;
        } else {
          System.out.println(top.data + " ");
          prev = s.pop();
        }
      }
    }
  }

  public static void levelOrder(Node root) {
    if (root == null)
      return;
    Queue<Node> q = new LinkedList<>();
    q.offer(root);
    while (!q.isEmpty()) {
      Node node = q.poll();
      System.out.println(node.data + " ");
      if (node.left != null)
        q.offer(node.left);
      if (node.right != null)
        q.offer(node.right);
    }
  }
}
