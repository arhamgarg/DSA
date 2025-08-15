class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Stack:
    def __init__(self):
        self.head = None
        self._size = 0

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node
        self._size += 1

    def pop(self):
        if self.head is None:
            print("Stack Underflow")
            return
        self.head = self.head.next
        self._size -= 1

    def top(self):
        if self.head is None:
            print("Stack Underflow")
            return
        print(self.head.data)

    def is_empty(self):
        return self.head is None

    def size(self):
        return self._size
