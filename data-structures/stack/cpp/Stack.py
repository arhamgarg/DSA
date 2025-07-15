class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class StackLL:
    def __init__(self):
        self.head = None
        self._size=0

    def push(self, value):
        new_node = Node(value)
        new_node.next = self.head  
        self.head = new_node       
        self._size += 1
        self.display()

    def pop(self):
        if self.is_empty():
            print("Stack Underflow")
        popped = self.head.data
        self.head = self.head.next  
        self._size -= 1
        print(popped)
        self.display()

    def top(self):
        if self.is_empty():
            print("Stack Underflow")
        else:
            print(self.head.data)
    
    def is_empty(self):
        return self.head is None
    
    def size(self):
        return self._size

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")


