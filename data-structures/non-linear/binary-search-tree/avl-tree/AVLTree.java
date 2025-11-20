class Node {
    int data;
    Node left;
    Node right;
    int height;

    public Node(int data) {
        this.data = data;
        this.left = this.right = null;
        height = 1;
    }
}

public class AVLTree {
    Node root;

    public AVLTree() {
        root = null;
    }


    int height(Node node) {
        return (node == null) ? 0 : node.height;
    }

    int balanceFactor(Node node) {
        return (node == null) ? 0 : height(node.left) - height(node.right);
    }

    Node rightRotate(Node y) {
        Node x = y.left;
        Node T2 = x.right;

        x.right = y;
        y.left = T2;

        y.height = Math.max(height(y.left), height(y.right)) + 1;
        x.height = Math.max(height(x.left), height(x.right)) + 1;

        return x;
    }

    Node leftRotate(Node x) {
        Node y = x.right;
        Node T2 = y.left;

        y.left = x;
        x.right = T2;

        x.height = Math.max(height(x.left), height(x.right)) + 1;
        y.height = Math.max(height(y.left), height(y.right)) + 1;

        return y;
    }

    Node insert(Node node, int value) {
        if (node == null) {
            return new Node(value);
        }

        if (value < node.data) {
            node.left = insert(node.left, value);
        } else if (value > node.data) {
            node.right = insert(node.right, value);
        } else {
            return node;
        }

        node.height = 1 + Math.max(height(node.left), height(node.right));

        int balance = balanceFactor(node);

        // left left
        if (balance > 1 && value < node.left.data) {
            return rightRotate(node);
        }

        // light right
        if (balance < -1 && value > node.right.data) {
            return leftRotate(node);
        }

        // left right
        if (balance > 1 && value > node.left.data) {
            node.left = leftRotate(node.left);
            return rightRotate(node);
        }

        // right left
        if (balance < -1 && value < node.right.data) {
            node.right = rightRotate(node.right);
            return leftRotate(node);
        }

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inorder() {
        inorderTraversal(root);
        System.out.println();
    }

    void inorderTraversal(Node root) {
        if (root == null)
            return;

        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

}
