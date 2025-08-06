class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
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
        if self.head is not None:
            self.head.prev = new_node
        self.head = new_node
        if self.tail is None:
            self.tail = new_node
        self._size += 1
        print(f"Inserted at front: {item}")

    def insertRear(self, item):
        new_node = Node(item)
        new_node.prev = self.tail
        if self.tail is not None:
            self.tail.next = new_node
        self.tail = new_node
        if self.head is None:
            self.head = new_node
        self._size += 1
        print(f"Inserted at rear: {item}")

    def deleteFront(self):
        if self.isEmpty():
            print("Deque is empty! Cannot delete from front.")
            return None
        removed = self.head.data
        self.head = self.head.next
        if self.head is not None:
            self.head.prev = None
        else:
            self.tail = None
        self._size -= 1
        print(f"Deleted from front: {removed}")
        return removed

    def deleteRear(self):
        if self.isEmpty():
            print("Deque is empty! Cannot delete from rear.")
            return None
        removed = self.tail.data
        self.tail = self.tail.prev
        if self.tail is not None:
            self.tail.next = None
        else:
            self.head = None
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
            print(current.data, end=" <-> ")
            current = current.next
        print("None")
