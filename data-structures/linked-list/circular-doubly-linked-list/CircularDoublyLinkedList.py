class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None


class CircularDoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insertFirst(self, val):
        new_node = Node(val)
        if self.head is None:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            new_node.prev = self.tail
            self.head.prev = new_node
            self.tail.next = new_node
            self.head = new_node

    def insertLast(self, val):
        new_node = Node(val)
        if self.head is None:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = self.tail = new_node
        else:
            new_node.prev = self.tail
            new_node.next = self.head
            self.tail.next = new_node
            self.head.prev = new_node
            self.tail = new_node

    def deleteFirst(self):
        if self.head is None:
            return
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = self.tail
            self.tail.next = self.head

    def deleteLast(self):
        if self.head is None:
            return
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = self.head
            self.head.prev = self.tail

    def insertAfter(self, u, v):
        if self.head is None:
            print(f"Value {u} not found in list.")
            return
        curr = self.head
        while True:
            if curr.val == u:
                new_node = Node(v)
                new_node.next = curr.next
                new_node.prev = curr
                curr.next.prev = new_node
                curr.next = new_node
                if curr == self.tail:
                    self.tail = new_node
                return
            curr = curr.next
            if curr == self.head:
                break
        print(f"Value {u} not found in list.")

    def linear_search(self, target):
        if self.head is None:
            return -1
        index = 0
        curr = self.head
        while True:
            if curr.val == target:
                return index
            curr = curr.next
            index += 1
            if curr == self.head:
                break
        return -1

    def listSize(self):
        if self.head is None:
            return 0
        size = 1
        curr = self.head.next
        while curr != self.head:
            size += 1
            curr = curr.next
        return size

    def isEmpty(self):
        return self.head is None

    def printList(self):
        if self.head is None:
            print("Empty list")
            return
        curr = self.head
        while True:
            print(curr.val, end=" <-> ")
            curr = curr.next
            if curr == self.head:
                break
        print("(back to head)")
