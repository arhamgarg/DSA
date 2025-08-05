class TreeNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __str__(self):
        return str(self.val)


class BinaryTree:
    def __init__(self, root=None):
        self.root = root

    def pre_order(self, node):
        if not node:
            return
        print(node, end=" ")
        self.pre_order(node.left)
        self.pre_order(node.right)

    def in_order(self, node):
        if not node:
            return
        self.in_order(node.left)
        print(node, end=" ")
        self.in_order(node.right)

    def post_order(self, node):
        if not node:
            return
        self.post_order(node.left)
        self.post_order(node.right)
        print(node, end=" ")

    def level_order(self):
        if not self.root:
            return

        from collections import deque

        queue = deque([self.root])

        while queue:
            node = queue.popleft()
            print(node, end=" ")
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
