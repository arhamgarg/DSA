class Queue:
    class QNode:
        def __init__(self, data):
            self.data = data
            self.next = None

    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def enqueue(self, data):
        n = self.QNode(data)
        if self.count == 0:
            self.head = self.tail = n
        else:
            self.tail.next = n
            self.tail = n
        self.count += 1

    def dequeue(self):
        if self.count == 0:
            return None
        val = self.head.data
        self.head = self.head.next
        self.count -= 1
        if self.count == 0:
            self.tail = None
        return val

    def isEmpty(self):
        return self.count == 0


class BinarySearchTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def insert(self, node):
        self.root = self.insertHelper(self.root, node)

    def insertHelper(self, root, node):
        if root is None:
            return node
        if node.data < root.data:
            root.left = self.insertHelper(root.left, node)
        elif node.data > root.data:
            root.right = self.insertHelper(root.right, node)
        return root

    def display(self, root):
        if root is not None:
            self.display(root.left)
            print(root.data, end=" ")
            self.display(root.right)

    def search(self, root, data):
        if root is None:
            return False
        if root.data == data:
            return True
        elif data < root.data:
            return self.search(root.left, data)
        else:
            return self.search(root.right, data)

    def remove(self, root, data):
        if not self.search(self.root, data):
            print(f"{data} could not be found")
            return self.root
        return self.removeHelper(root, data)

    def removeHelper(self, root, data):
        if root is None:
            return root
        if data < root.data:
            root.left = self.removeHelper(root.left, data)
        elif data > root.data:
            root.right = self.removeHelper(root.right, data)
        else:
            if root.left is None and root.right is None:
                return None
            elif root.right is not None:
                succ_value = self.successor(root)
                root.data = succ_value
                root.right = self.removeHelper(root.right, succ_value)
            else:
                pred_value = self.predecessor(root)
                root.data = pred_value
                root.left = self.removeHelper(root.left, pred_value)
        return root

    def height(self, root):
        if root is None:
            return 0
        lh = self.height(root.left)
        rh = self.height(root.right)
        return max(lh, rh) + 1

    def findMin(self, root):
        if root is None:
            return None
        current = root
        while current.left is not None:
            current = current.left
        return current.data

    def findMax(self, root):
        if root is None:
            return None
        current = root
        while current.right is not None:
            current = current.right
        return current.data

    def successor(self, root):
        root = root.right
        while root.left is not None:
            root = root.left
        return root.data

    def predecessor(self, root):
        root = root.left
        while root.right is not None:
            root = root.right
        return root.data

    def levelOrder(self):
        if self.root is None:
            return
        q = Queue()
        q.enqueue(self.root)
        while not q.isEmpty():
            node = q.dequeue()
            print(node.data, end=" ")
            if node.left:
                q.enqueue(node.left)
            if node.right:
                q.enqueue(node.right)


# ------------------ MAIN ------------------
if __name__ == "__main__":
    tree = BinarySearchTree()
    for val in [5, 1, 9, 7, 3, 6, 4, 8]:
        tree.insert(BinarySearchTree.Node(val))

    print("In-order Traversal:")
    tree.display(tree.root)
    print("\nLevel Order Traversal:")
    tree.levelOrder()

    print("\nSearch 1:", tree.search(tree.root, 1))
    print("Search 10:", tree.search(tree.root, 10))

    print("Min:", tree.findMin(tree.root))
    print("Max:", tree.findMax(tree.root))
    print("Height:", tree.height(tree.root))

    print("\nRemoving 5...")
    tree.root = tree.remove(tree.root, 5)
    print("In-order after removal:")
    tree.display(tree.root)
