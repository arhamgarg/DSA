from collections import deque


class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


def pre_order(root):
    if not root:
        return

    stack = [root]
    while stack:
        node = stack.pop()
        print(node.data, end=" ")

        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)


def in_order(root):
    stack = []
    current = root

    while stack or current:
        if current:
            stack.append(current)
            current = current.left
        else:
            current = stack.pop()
            print(current.data, end=" ")
            current = current.right


def post_order(root):
    stack = []
    last_visited = None
    current = root

    while stack or current:
        if current:
            stack.append(current)
            current = current.left
        else:
            top = stack[-1]
            if top.right and last_visited != top.right:
                current = top.right
            else:
                print(top.data, end=" ")
                last_visited = stack.pop()


def level_order(root):
    if not root:
        return

    queue = deque([root])

    while queue:
        node = queue.popleft()
        print(node.data, end=" ")

        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
