class Node:
    def __init__(self, value):
        self.data = value
        self.left = None
        self.right = None

def pre_order(root):
    stack=[root]
    while stack:
        root=stack.pop()
        if root.right:
            stack.append(root.right)
        if root.left:
            stack.append(root.left)
        print(root.data, end=" ")

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
            peek = stack[-1]
            if peek.right and last_visited != peek.right:
                current = peek.right
            else:
                print(peek.data, end=" ")
                last_visited = stack.pop()

def level_order(root):
    if not root:
        return
    
    queue = [root]  
    
    while queue:
        current = queue.pop(0)   
        print(current.data, end=" ")
        
        if current.left:
            queue.append(current.left)
        if current.right:
            queue.append(current.right)
