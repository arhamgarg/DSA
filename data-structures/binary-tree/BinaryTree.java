import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    public Node(int data) {
        this.data = data;
        left = right = null;
    }
}

class Queue {
    static class QNode {
        Node data;
        QNode next;

        QNode(Node data) {
            this.data = data;
            this.next = null;
        }
    }

    QNode front, rear;

    Queue() {
        this.front = this.rear = null;
    }

    void enqueue(Node data) {
        QNode temp = new QNode(data);
        if (this.rear == null) {
            this.front = this.rear = temp;
            return;
        }
        this.rear.next = temp;
        this.rear = temp;
    }

    Node dequeue() {
        if (this.front == null)
            return null;

        QNode temp = this.front;
        this.front = this.front.next;

        if (this.front == null)
            this.rear = null;

        return temp.data;
    }

    boolean isEmpty() {
        return front == null;
    }
}

class BinaryTree {
    int idx = -1;

    Node buildTree(int[] nodes) {
        idx++;
        if (idx >= nodes.length || nodes[idx] == -1)
            return null;

        Node newNode = new Node(nodes[idx]);
        newNode.left = buildTree(nodes);
        newNode.right = buildTree(nodes);
        return newNode;
    }

    void preorder(Node root) {
        if (root == null) return;
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    void postorder(Node root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    void levelorder(Node root) {
        if (root == null) return;
        Queue q = new Queue();
        q.enqueue(root);

        while (!q.isEmpty()) {
            Node curr = q.dequeue();
            System.out.print(curr.data + " ");
            if (curr.left != null)
                q.enqueue(curr.left);
            if (curr.right != null)
                q.enqueue(curr.right);
        }
    }

    int height(Node root) {
        if (root == null)
            return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }

    int countNodes(Node root) {
        if (root == null)
            return 0;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }

    int sumOfNodes(Node root) {
        if (root == null)
            return 0;
        return root.data + sumOfNodes(root.left) + sumOfNodes(root.right);
    }
}

public class TreeDemo {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();

        // Sample tree: [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1]
        int[] nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

        Node root = bt.buildTree(nodes);

        System.out.println("Preorder:");
        bt.preorder(root);
        System.out.println("\nInorder:");
        bt.inorder(root);
        System.out.println("\nPostorder:");
        bt.postorder(root);
        System.out.println("\nLevel Order:");
        bt.levelorder(root);

        System.out.println("\n\nTree Height: " + bt.height(root));
        System.out.println("Total Nodes: " + bt.countNodes(root));
        System.out.println("Sum of Nodes: " + bt.sumOfNodes(root));
    }
}
