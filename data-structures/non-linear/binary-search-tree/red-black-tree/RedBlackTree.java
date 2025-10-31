class Node {
    int data;
    String color;
    Node left, right, parent;

    Node(int value) {
        data = value;
        color = "RED";
        left = right = parent = null;
    }
}

public class RedBlackTree {
    Node root;
    Node NIL;

    public RedBlackTree() {
        NIL = new Node(0);
        NIL.color = "BLACK";
        NIL.left = NIL.right = NIL;
        root = NIL;
    }

    private void rotateLeft(Node x) {
        Node y = x.right;

        x.right = y.left;
        if (y.left != NIL) {
            y.left.parent = x;
        }

        y.parent = x.parent;

        if (x.parent == null) {
            root = y;
        } else if (x == x.parent.left) {
            x.parent.left = y;
        } else {
            x.parent.right = y;
        }

        y.left = x;
        x.parent = y;
    }

    private void rotateRight(Node x) {
        Node y = x.left;

        x.left = y.right;
        if (y.right != NIL) {
            y.right.parent = x;
        }

        y.parent = x.parent;

        if (x.parent == null) {
            root = y;
        } else if (x == x.parent.right) {
            x.parent.right = y;
        } else {
            x.parent.left = y;
        }

        y.right = x;
        x.parent = y;
    }

    private void fixInsert(Node k) {
        while (k != root && k.parent.color.equals("RED")) {
            if (k.parent == k.parent.parent.left) {
                Node u = k.parent.parent.right;

                if (u.color.equals("RED")) {
                    k.parent.color = "BLACK";
                    u.color = "BLACK";
                    k.parent.parent.color = "RED";
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.right) {
                        k = k.parent;
                        rotateLeft(k);
                    }
                    k.parent.color = "BLACK";
                    k.parent.parent.color = "RED";
                    rotateRight(k.parent.parent);
                }
            } else {
                Node u = k.parent.parent.left;

                if (u.color.equals("RED")) {
                    k.parent.color = "BLACK";
                    u.color = "BLACK";
                    k.parent.parent.color = "RED";
                    k = k.parent.parent;
                } else {
                    if (k == k.parent.left) {
                        k = k.parent;
                        rotateRight(k);
                    }
                    k.parent.color = "BLACK";
                    k.parent.parent.color = "RED";
                    rotateLeft(k.parent.parent);
                }
            }
        }
        root.color = "BLACK";
    }

    public void insert(int data) {
        Node newNode = new Node(data);
        newNode.left = NIL;
        newNode.right = NIL;

        Node parent = null;
        Node current = root;

        while (current != NIL) {
            parent = current;
            if (newNode.data < current.data) {
                current = current.left;
            } else {
                current = current.right;
            }
        }

        newNode.parent = parent;

        if (parent == null) {
            root = newNode;
        } else if (newNode.data < parent.data) {
            parent.left = newNode;
        } else {
            parent.right = newNode;
        }

        if (newNode.parent == null) {
            newNode.color = "BLACK";
            return;
        }

        if (newNode.parent.parent == null) {
            return;
        }

        fixInsert(newNode);
    }

    public void inorderTraversal(Node node) {
        if (node != NIL) {
            inorderTraversal(node.left);
            System.out.print(node.data + " ");
            inorderTraversal(node.right);
        }
    }

    public Node search(Node node, int data) {
        if (node == NIL || data == node.data) {
            return node;
        }

        if (data < node.data) {
            return search(node.left, data);
        }

        return search(node.right, data);
    }
}