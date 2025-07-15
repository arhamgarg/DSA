class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class QueueLL:
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
        self.display()

   
    def dequeue(self):
        if self.is_empty():
            print("Queue is empty")
        popped = self.head.data
        self.head = self.head.next
        self._size -= 1
        print(popped)
        self.display()

  
    def top(self):
        if self.is_empty():
            print("Queue is empty")
        else:
            print(self.head.data)
            self.display()

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


