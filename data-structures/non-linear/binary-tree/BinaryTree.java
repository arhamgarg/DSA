// TreeWithCustomQueue.java
// Mirrors your Python code: build, delete (using deepest node), traversals,
// height, depth, findNode, addChild, subtree height, LCA, completeness check.
// Uses a hand-rolled linked-list Queue (no java.util).

class Queue {
  private static class QNode {
    TreeNode data;
    QNode next;

    QNode(TreeNode d) {
      this.data = d;
    }
  }

  private QNode head, tail;
  private int count = 0;

  public void enqueue(TreeNode node) {
    QNode n = new QNode(node);
    if (count == 0) {
      head = tail = n;
    } else {
      tail.next = n;
      tail = n;
    }
    count++;
  }

  public TreeNode dequeue() {
    if (count == 0)
      return null;
    TreeNode val = head.data;
    head = head.next;
    count--;
    if (count == 0)
      tail = null;
    return val;
  }

  public boolean isEmpty() {
    return count == 0;
  }

  public int size() {
    return count;
  }
}

class TreeNode {
  int data;
  TreeNode left, right;

  TreeNode(int d) {
    data = d;
  }
}

class Tree {
  TreeNode root = null;
  int index = -1; // for build

  // Build from pre-order array with nulls/-1 as empty
  TreeNode buildTree(Integer[] arr) {
    index++;
    if (index >= arr.length || arr[index] == null || arr[index] == -1)
      return null;
    TreeNode node = new TreeNode(arr[index]);
    if (root == null)
      root = node;
    node.left = buildTree(arr);
    node.right = buildTree(arr);
    return node;
  }

  // Delete node by value: replace with deepest (last in level order) then remove
  // deepest
  TreeNode deleteNode(TreeNode root, int value) {
    if (root == null)
      return null;

    // if single node
    if (root.left == null && root.right == null) {
      return (root.data == value) ? null : root;
    }

    Queue q = new Queue();
    q.enqueue(root);
    TreeNode nodeToDelete = null;
    TreeNode last = null;
    TreeNode parentOfLast = null;

    while (!q.isEmpty()) {
      last = q.dequeue();
      if (last.data == value)
        nodeToDelete = last;

      if (last.left != null) {
        parentOfLast = last;
        q.enqueue(last.left);
      }
      if (last.right != null) {
        parentOfLast = last;
        q.enqueue(last.right);
      }
    }

    if (nodeToDelete == null) {
      System.out.println("Value not found in tree");
      return root;
    }

    // Replace value
    nodeToDelete.data = last.data;

    // Remove deepest child from its parent
    if (parentOfLast != null) {
      if (parentOfLast.left == last)
        parentOfLast.left = null;
      else if (parentOfLast.right == last)
        parentOfLast.right = null;
    } else {
      // If for some reason parentOfLast is null, it means root was last and had no
      // parent.
      // That case is already handled above for single node trees.
    }
    return root;
  }

  void preOrder(TreeNode r) {
    if (r == null)
      return;
    System.out.print(r.data + " ");
    preOrder(r.left);
    preOrder(r.right);
  }

  void postOrder(TreeNode r) {
    if (r == null)
      return;
    postOrder(r.left);
    postOrder(r.right);
    System.out.print(r.data + " ");
  }

  void inOrder(TreeNode r) {
    if (r == null)
      return;
    inOrder(r.left);
    System.out.print(r.data + " ");
    inOrder(r.right);
  }

  void levelOrder(TreeNode r) {
    if (r == null) {
      System.out.println();
      return;
    }
    Queue q = new Queue();
    q.enqueue(r);
    while (!q.isEmpty()) {
      TreeNode n = q.dequeue();
      System.out.print(n.data + " ");
      if (n.left != null)
        q.enqueue(n.left);
      if (n.right != null)
        q.enqueue(n.right);
    }
    System.out.println();
  }

  int height(TreeNode r) {
    if (r == null)
      return 0;
    int lh = height(r.left), rh = height(r.right);
    return Math.max(lh, rh) + 1;
  }

  int depth(TreeNode r, int value) {
    if (r == null)
      return -1;
    if (r.data == value)
      return 0;
    int left = depth(r.left, value);
    if (left != -1)
      return left + 1;
    int right = depth(r.right, value);
    if (right != -1)
      return right + 1;
    return -1;
  }

  TreeNode findNode(TreeNode r, int value) {
    if (r == null)
      return null;
    if (r.data == value)
      return r;
    TreeNode L = findNode(r.left, value);
    if (L != null)
      return L;
    return findNode(r.right, value);
  }

  boolean addChild(TreeNode r, int parent, int child) {
    TreeNode p = findNode(r, parent);
    if (p == null)
      return false;
    TreeNode c = new TreeNode(child);
    if (p.left == null) {
      p.left = c;
      return true;
    }
    if (p.right == null) {
      p.right = c;
      return true;
    }
    return false;
  }

  int findHeightSubtree(TreeNode r, int value) {
    TreeNode n = findNode(r, value);
    return (n == null) ? -1 : height(n);
  }

  TreeNode findCommonAncestor(TreeNode r, int a, int b) {
    if (r == null)
      return null;
    if (r.data == a || r.data == b)
      return r;
    TreeNode L = findCommonAncestor(r.left, a, b);
    TreeNode R = findCommonAncestor(r.right, a, b);
    if (L != null && R != null)
      return r;
    return (L != null) ? L : R;
  }

  boolean checkCompleteTree(TreeNode r) {
    if (r == null)
      return false;
    Queue q = new Queue();
    q.enqueue(r);
    boolean end = false;
    while (!q.isEmpty()) {
      TreeNode n = q.dequeue();
      if (n.left != null) {
        if (end)
          return false;
        q.enqueue(n.left);
      } else {
        end = true;
      }
      if (n.right != null) {
        if (end)
          return false;
        q.enqueue(n.right);
      } else {
        end = true;
      }
    }
    return true;
  }
}

public class BinaryTree {
  public static void main(String[] args) {
    Tree t = new Tree();
    Integer[] arr = { 1, 2, 3, 4, 5, null, 8, null, 6, null, null, null, 9, null, null, 7, null };
    t.buildTree(arr);

    System.out.println("Pre-order:");
    t.preOrder(t.root);
    System.out.println();

    System.out.println("Post-order:");
    t.postOrder(t.root);
    System.out.println();

    System.out.println("In-order:");
    t.inOrder(t.root);
    System.out.println();

    System.out.println("Level order:");
    t.levelOrder(t.root);

    t.root = t.deleteNode(t.root, 2);

    System.out.println("After deletion of 2:");
    t.levelOrder(t.root);

    System.out.println("Height of Tree: " + t.height(t.root));
    System.out.println("Depth of 9: " + t.depth(t.root, 9));

    TreeNode found5 = t.findNode(t.root, 5);
    System.out.println("Find Node 5: " + (found5 != null ? found5.data : "Not found"));

    System.out.println("Add child 10 under 3: " + t.addChild(t.root, 3, 10));
    t.levelOrder(t.root);

    System.out.println("Height of subtree rooted at 3: " + t.findHeightSubtree(t.root, 3));

    TreeNode ancestor = t.findCommonAncestor(t.root, 6, 9);
    System.out.println("Lowest Common Ancestor of 6 and 9: " + (ancestor != null ? ancestor.data : "None"));

    System.out.println("Is tree complete? " + t.checkCompleteTree(t.root));
  }
}
