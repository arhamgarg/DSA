class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class Deque:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def insert_front(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.next = self.front
            self.front.prev = new_node
            self.front = new_node
        self.size += 1

    def insert_rear(self, data):
        new_node = Node(data)
        if self.is_empty():
            self.front = self.rear = new_node
        else:
            new_node.prev = self.rear
            self.rear.next = new_node
            self.rear = new_node
        self.size += 1

    def delete_front(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        value = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        else:
            self.front.prev = None
        self.size -= 1
        return value

    def delete_rear(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        value = self.rear.data
        self.rear = self.rear.prev
        if self.rear is None:
            self.front = None
        else:
            self.rear.next = None
        self.size -= 1
        return value

    def get_front(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        return self.front.data

    def get_rear(self):
        if self.is_empty():
            raise IndexError("Deque is empty")
        return self.rear.data

    def __len__(self):
        return self.size
