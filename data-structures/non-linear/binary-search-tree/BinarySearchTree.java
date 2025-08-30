public class BinarySearchTree {

    public static class Node {
        int data;
        Node left;
        Node right;

        public Node(int data) {
            this.data = data;
        }
    }

    public static class Queue {
        private static class QNode {
            Node data;
            QNode next;

            QNode(Node d) {
                this.data = d;
            }
        }

        private QNode head, tail;
        private int count = 0;

        public void enqueue(Node node) {
            QNode n = new QNode(node);
            if (count == 0) {
                head = tail = n;
            } else {
                tail.next = n;
                tail = n;
            }
            count++;
        }

        public Node dequeue() {
            if (count == 0)
                return null;
            Node val = head.data;
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

    Node root;

    // helper method are here because we are going to use Recursion
    public void insert(Node node) {
        root = insertHelper(root, node);

    }

    private Node insertHelper(Node root, Node node) {
        int data = node.data; // this method searches for data as mentioned in the text of das1.txt
        if (root == null) {
            root = node;
            return root;
        } else if (data < root.data) {
            root.left = insertHelper(root.left, node);
        } else if (data > root.data) {
            root.right = insertHelper(root.right, node);
        }
        return root;
    }

    public void display() {
        displayHelper(root);
    }

    private void displayHelper(Node root) {
        if (root != null) {
            displayHelper(root.left);
            System.out.print(root.data + " ");
            displayHelper(root.right); // for descending order interchange the positions of both right and left
        }
    }

    public boolean search(int data) {
        return searchHelper(root, data);
    }

    private boolean searchHelper(Node root, int data) {
        if (root == null) {
            return false;
        } else if (root.data == data) {
            return true;
        } else if (root.data > data) {
            return searchHelper(root.left, data);
        } else {
            return searchHelper(root.right, data);
        }
    }

    public void remove(int data) {
        if (search(data)) {
            removeHelper(root, data);
        } else {
            System.out.println(data + "could not be found");
        }
    }

    public void Pre_Order(Node root) {
        if (root == null)
            return;
        System.out.print(root.data + " ");
        Pre_Order(root.left);
        Pre_Order(root.right);
    }

    public void Post_Order(Node root) {
        if (root == null)
            return;
        Post_Order(root.left);
        Post_Order(root.right);
        System.out.print(root.data + " ");
    }

    public void Level_Order(Node root) {
        if (root == null) {
            System.out.println();
            return;
        }
        Queue q = new Queue();
        q.enqueue(root);
        while (!q.isEmpty()) {
            Node n = q.dequeue();
            System.out.print(n.data + " ");
            if (n.left != null)
                q.enqueue(n.left);
            if (n.right != null)
                q.enqueue(n.right);
        }
        System.out.println();
    }

    private Node removeHelper(Node root, int data) {
        if (root == null) {
            return root;

        } else if (data < root.data) {
            root.left = removeHelper(root.left, data);
        } else if (data > root.data) {
            root.right = removeHelper(root.right, data);
        } else {// node found
                // if the node we are trying to remove has children, then it kinda complicates
                // things
            if (root.left == null && root.right == null) { // leaf node
                root = null;
            } else if (root.right != null) {// find a successor to replace this node
                int success_Value = successor(root);
                root.data = success_Value;
                root.right = removeHelper(root.right, success_Value);
            } else {// finds a predecessor to replace this node
                root.data = predecessor(root);
                root.left = removeHelper(root.left, data);
            }
        }
        return root;
    }

    int height(Node root) {
        if (root == null)
            return 0;
        int lh = height(root.left), rh = height(root.right);
        return Math.max(lh, rh) + 1;
    }

    public int findMin() {
        if (root == null) {
            System.out.println("Tree is empty");
            return 0;
        }
        Node current = root;
        while (current.left != null) {
            current = current.left;
        }
        return current.data;
    }

    public int findMax() {
        if (root == null) {
            System.out.println("Tree is empty");
            return 0;
        }
        Node current = root;
        while (current.right != null) {
            current = current.right;
        }
        return current.data;
    }

    private int successor(Node root) { // find the least value below the right child of this root node
        root = root.right;
        while (root.left != null) {
            root = root.left;
        }

        return root.data;
    }

    private int predecessor(Node root) {// find the greatest value below the left child of this root node
        root = root.left;
        while (root.right != null) {
            root = root.right;
        }
        return root.data;
    }

    /*
     * Binary Search Tree = A tree data structure, where each node is greater than
     * it's left child,
     * but less than it's right.
     *
     * benefit: easy to locate a node when they are in this order
     *
     * time complexity: best case = O(log n)
     * worst case = O(n)
     * space complexity: O(n)
     */
    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();

        tree.insert(new Node(5));
        tree.insert(new Node(1));
        tree.insert(new Node(9));
        tree.insert(new Node(7));
        tree.insert(new Node(3));
        tree.insert(new Node(6));
        tree.insert(new Node(4));
        tree.insert(new Node(8));

        System.out.println("In-order (Ascending):");
        tree.display();
        System.out.println();

        System.out.println("Pre-order:");
        tree.Pre_Order(tree.root);
        System.out.println();

        System.out.println("Post-order:");
        tree.Post_Order(tree.root);
        System.out.println();

        System.out.println("Level Order:");
        tree.Level_Order(tree.root);

        System.out.println("Min value: " + tree.findMin());
        System.out.println("Max value: " + tree.findMax());
        System.out.println("Height: " + tree.height(tree.root));

        System.out.println("Search 1: " + tree.search(1));
        System.out.println("Search 10: " + tree.search(10));

        tree.remove(5);
        System.out.println("In-order after removing 5:");
        tree.display();
    }

}
