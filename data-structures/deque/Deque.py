class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Deque:
    def __init__(self):
        self.head = None
        self.tail = None
        self._size = 0

    def isEmpty(self):
        return self.head is None

    def insertFront(self, item):
        new_node = Node(item)
        new_node.next = self.head
        self.head = new_node
        if self.tail is None:  # First node
            self.tail = new_node
        self._size += 1
        print(f"Inserted at front: {item}")

    def insertRear(self, item):
        new_node = Node(item)
        if self.tail is None:  # Empty deque
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self._size += 1
        print(f"Inserted at rear: {item}")

    def deleteFront(self):
        if self.isEmpty():
            print("Deque is empty! Cannot delete from front.")
            return None
        removed = self.head.data
        self.head = self.head.next
        if self.head is None:  # List became empty
            self.tail = None
        self._size -= 1
        print(f"Deleted from front: {removed}")
        return removed

    def deleteRear(self):
        if self.isEmpty():
            print("Deque is empty! Cannot delete from rear.")
            return None
        if self.head == self.tail:  # Only one node
            removed = self.tail.data
            self.head = self.tail = None
            self._size -= 1
            print(f"Deleted from rear: {removed}")
            return removed
        # Traverse to second-last node
        current = self.head
        while current.next != self.tail:
            current = current.next
        removed = self.tail.data
        current.next = None
        self.tail = current
        self._size -= 1
        print(f"Deleted from rear: {removed}")
        return removed

    def getFront(self):
        if self.isEmpty():
            print("Deque is empty!")
            return None
        return self.head.data

    def getRear(self):
        if self.isEmpty():
            print("Deque is empty!")
            return None
        return self.tail.data

    def size(self):
        return self._size

    def display(self):
        print("Deque contents:", end=" ")
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")
