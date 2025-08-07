class Queue:
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

    def __init__(self):
        self.head = None
        self.tail = None
        self.length = 0

    def enqueue(self, data):
        new_node = self.Node(data)
        if self.tail:
            self.tail.next = new_node
        self.tail = new_node
        if self.head is None:
            self.head = new_node
        self.length += 1

    def dequeue(self):
        if self.length == 0:
            return None
        removed = self.head
        self.head = self.head.next
        if self.head is None:
            self.tail = None
        self.length -= 1
        return removed.data

    def isEmpty(self):
        return self.length == 0

    def size(self):
        return self.length


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.idx = -1

    def build_tree(self, nodes):
        self.idx += 1
        if self.idx >= len(nodes) or nodes[self.idx] == -1:
            return None

        new_node = Node(nodes[self.idx])
        new_node.left = self.build_tree(nodes)
        new_node.right = self.build_tree(nodes)
        return new_node

    def preorder(self, root):
        if root is None:
            return
        print(root.data, end=" ")
        self.preorder(root.left)
        self.preorder(root.right)

    def inorder(self, root):
        if root is None:
            return
        self.inorder(root.left)
        print(root.data, end=" ")
        self.inorder(root.right)

    def postorder(self, root):
        if root is None:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.data, end=" ")

    def levelorder(self, root):
        if root is None:
            return
        q = Queue()
        q.enqueue(root)
        while not q.isEmpty():
            current = q.dequeue()
            print(current.data, end=" ")
            if current.left:
                q.enqueue(current.left)
            if current.right:
                q.enqueue(current.right)

    def height(self, root):
        if root is None:
            return 0
        return 1 + max(self.height(root.left), self.height(root.right))

    def count_nodes(self, root):
        if root is None:
            return 0
        return 1 + self.count_nodes(root.left) + self.count_nodes(root.right)

    def sum_of_nodes(self, root):
        if root is None:
            return 0
        return root.data + self.sum_of_nodes(root.left) + self.sum_of_nodes(root.right)


# ---------- Sample usage ----------
nodes = [1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1]

bt = BinaryTree()
root = bt.build_tree(nodes)

print("Preorder:")
bt.preorder(root)
print("\nInorder:")
bt.inorder(root)
print("\nPostorder:")
bt.postorder(root)
print("\nLevel Order:")
bt.levelorder(root)

print("\n\nTree Height:", bt.height(root))
print("Total Nodes:", bt.count_nodes(root))
print("Sum of Nodes:", bt.sum_of_nodes(root))
