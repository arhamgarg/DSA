class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None


def insert(root, value):
    if root is None:
        return Node(value)

    if value < root.data:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)

    return root


def buildBST(values):
    root = None
    for val in values:
        root = insert(root, val)
    return root


def inorderTraversal(root):
    if root is None:
        return
    inorderTraversal(root.left)
    print(root.data, end=" ")
    inorderTraversal(root.right)


def search(root, key):
    if root is None:
        return False
    if root.data == key:
        return True
    if key < root.data:
        return search(root.left, key)
    else:
        return search(root.right, key)


def getInorderSuccessor(root):
    current = root
    while current is not None and current.left is not None:
        current = current.left
    return current


def deleteNode(root, key):
    if root is None:
        return None

    if key < root.data:
        root.left = deleteNode(root.left, key)
    elif key > root.data:
        root.right = deleteNode(root.right, key)
    else:
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left

        successor = getInorderSuccessor(root.right)
        root.data = successor.data
        root.right = deleteNode(root.right, successor.data)

    return root
