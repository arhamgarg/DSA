from collections import deque


class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


index = -1


def build_tree(preorder):
    global index
    index += 1

    if index >= len(preorder) or preorder[index] == -1:
        return None

    root = Node(preorder[index])
    root.left = build_tree(preorder)
    root.right = build_tree(preorder)

    return root


def preorder_traversal(root):
    if root is None:
        return
    print(root.data, end=" ")
    preorder_traversal(root.left)
    preorder_traversal(root.right)


def inorder_traversal(root):
    if root is None:
        return
    inorder_traversal(root.left)
    print(root.data, end=" ")
    inorder_traversal(root.right)


def postorder_traversal(root):
    if root is None:
        return
    postorder_traversal(root.left)
    postorder_traversal(root.right)
    print(root.data, end=" ")


def levelorder_traversal(root):
    if not root:
        return

    q = deque()
    q.append(root)
    q.append(None)

    while q:
        temp = q.popleft()

        if temp is None:
            print()
            if q:
                q.append(None)
        else:
            print(temp.data, end=" ")
            if temp.left:
                q.append(temp.left)
            if temp.right:
                q.append(temp.right)
