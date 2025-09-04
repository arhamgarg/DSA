class Queue:
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None

    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def enqueue(self, data):
        newNode = self.Node(data)
        if self.count == 0:
            self.head = self.tail = newNode
        else:
            self.tail.next = newNode
            self.tail = newNode
        self.count += 1

    def dequeue(self):
        if self.count == 0:
            return None
        data = self.head.data
        self.head = self.head.next
        self.count -= 1
        if self.count == 0:
            self.tail = None
        return data

    def front(self):
        return None if self.count == 0 else self.head.data

    def isEmpty(self):
        return self.count == 0

    def size(self):
        return self.count

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")


class Tree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None
        self.index = -1

    def build_Tree(self, arr):
        self.index += 1
        if self.index >= len(arr) or arr[self.index] is None or arr[self.index] == -1:
            return None
        newNode = self.Node(arr[self.index])
        if self.root is None:
            self.root = newNode
        newNode.left = self.build_Tree(arr)
        newNode.right = self.build_Tree(arr)
        return newNode

    def delete_node(self, root, value):
#        1         1
#       / \       / \
#      2   3  to 5  3
#     / \       /
#    4   5     4   right most child will take place of the deleted one

        if root is None:
            return None

        # base condition
        if root.left is None and root.right is None:
            if root.data == value:
                return None
            else:
                return root

        #Find node to delete & last node using level order
        q = Queue()
        q.enqueue(root)
        node_to_delete = None
        last = None
        parent_of_last = None

        while not q.isEmpty():
            last = q.dequeue()

            if last.data == value:
                node_to_delete = last

            if last.left:
                parent_of_last = last
                q.enqueue(last.left)
            if last.right:
                parent_of_last = last
                q.enqueue(last.right)

        # If node not found
        if node_to_delete is None:
            print("Value not found in tree")
            return root

        # Replace value
        node_to_delete.data = last.data

        #  Delete deepest node
        if parent_of_last.left == last:
            parent_of_last.left = None
        elif parent_of_last.right == last:
            parent_of_last.right = None

        return root

    def Pre_Order(self, root):
        if root is None:
            return
        print(root.data, end=" ")
        self.Pre_Order(root.left)
        self.Pre_Order(root.right)

    def Post_Order(self, root):
        if root is None:
            return
        self.Post_Order(root.left)
        self.Post_Order(root.right)
        print(root.data, end=" ")

    def In_Order(self, root):
        if root is None:
            return
        self.In_Order(root.left)
        print(root.data, end=" ")
        self.In_Order(root.right)

    def level_order(self, root):
        if root is None:
            return
        q = Queue()
        q.enqueue(root)
        while not q.isEmpty():
            node = q.dequeue()
            print(node.data, end=" ")
            if node.left:
                q.enqueue(node.left)
            if node.right:
                q.enqueue(node.right)
        print()

    def height(self, root):
        if root is None:
            return 0
        return max(self.height(root.left), self.height(root.right)) + 1

    def depth(self, root, value):
        if root is None:
            return -1
        if root.data == value:
            return 0
        left = self.depth(root.left, value)
        if left != -1:
            return left + 1
        right = self.depth(root.right, value)
        if right != -1:
            return right + 1
        return -1

    def findNode(self, root, value):
        if root is None:
            return None
        if root.data == value:
            return root
        left = self.findNode(root.left, value)
        if left:
            return left
        right = self.findNode(root.right, value)
        return right

    def add_Child(self, root, parent, child):
        parentNode = self.findNode(root, parent)
        if not parentNode:
            return False
        newNode = self.Node(child)
        if parentNode.left is None:
            parentNode.left = newNode
            return True
        elif parentNode.right is None:
            parentNode.right = newNode
            return True
        return False

    def find_height_subtree(self, root, value):
        found = self.findNode(root, value)
        if found is None:
            return -1
        return self.height(found)

    def find_common_ancestor(self, root, child1, child2):
        if root is None:
            return None
        if root.data == child1 or root.data == child2:
            return root
        left = self.find_common_ancestor(root.left, child1, child2)
        right = self.find_common_ancestor(root.right, child1, child2)
        if left and right:
            return root
        return left if left else right

    def check_complete_tree(self, root):
        if root is None:
            return False
        q = Queue()
        q.enqueue(root)
        end = False
        while not q.isEmpty():
            node = q.dequeue()
            if node.left:
                if end:
                    return False
                q.enqueue(node.left)
            else:
                end = True
            if node.right:
                if end:
                    return False
                q.enqueue(node.right)
            else:
                end = True
        return True


# ---------------- Test ----------------
t = Tree()
arr = [1, 2, 3, 4, 5, None, 8, None, 6, None, None, None, 9, None, None, 7, None]
t.build_Tree(arr)

print("Pre-order:"); t.Pre_Order(t.root); print()
print("Post-order:"); t.Post_Order(t.root); print()
print("In-order:"); t.In_Order(t.root); print()
print("Level order:"); t.level_order(t.root)

t.root = t.delete_node(t.root, 2)

print("After deletion of 2:")
t.level_order(t.root)

print("Height of Tree:", t.height(t.root))
print("Depth of 9:", t.depth(t.root, 9))

print("Find Node 5:", t.findNode(t.root, 5).data if t.findNode(t.root, 5) else "Not found")

print("Add child 10 under 3:", t.add_Child(t.root, 3, 10))
t.level_order(t.root)

print("Height of subtree rooted at 3:", t.find_height_subtree(t.root, 3))

ancestor = t.find_common_ancestor(t.root, 6, 9)
print("Lowest Common Ancestor of 6 and 9:", ancestor.data if ancestor else "None")

print("Is tree complete?", t.check_complete_tree(t.root))

