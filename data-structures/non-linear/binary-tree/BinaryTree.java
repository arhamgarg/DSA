import java.util.*;

class Node {
  int data;
  Node left;
  Node right;

  Node(int value) {
    data = value;
    left = right = null;
  }
}

public class BinaryTree {
  static int index = -1;

  public static Node buildTree(int[] preorder) {
    index++;

    if (index >= preorder.length || preorder[index] == -1) {
      return null;
    }

    Node root = new Node(preorder[index]);
    root.left = buildTree(preorder);
    root.right = buildTree(preorder);

    return root;
  }

  public static void preorderTraversal(Node root) {
    if (root == null)
      return;

    System.out.print(root.data + " ");
    preorderTraversal(root.left);
    preorderTraversal(root.right);
  }

  public static void inorderTraversal(Node root) {
    if (root == null)
      return;

    inorderTraversal(root.left);
    System.out.print(root.data + " ");
    inorderTraversal(root.right);
  }

  public static void postorderTraversal(Node root) {
    if (root == null)
      return;

    postorderTraversal(root.left);
    postorderTraversal(root.right);
    System.out.print(root.data + " ");
  }

  public static void levelorderTraversal(Node root) {
    if (root == null)
      return;

    Queue<Node> q = new LinkedList<>();
    q.add(root);
    q.add(null);

    while (!q.isEmpty()) {
      Node temp = q.poll();

      if (temp == null) {
        System.out.println();
        if (!q.isEmpty()) {
          q.add(null);
        }
      } else {
        System.out.print(temp.data + " ");

        if (temp.left != null) {
          q.add(temp.left);
        }

        if (temp.right != null) {
          q.add(temp.right);
        }
      }
    }
  }
}
