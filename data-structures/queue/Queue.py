class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Queue:
    def __init__(self):
        self.head = None
        self._size = 0

    def enqueue(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = new_node
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty")
        self.head = self.head.next
        self._size -= 1

    def top(self):
        if self.is_empty():
            print("Queue is empty")
        print(self.head.data)

    def is_empty(self):
        return self.head is None

    def size(self):
        return self._size
