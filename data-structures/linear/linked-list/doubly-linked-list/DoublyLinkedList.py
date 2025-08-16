class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insertFirst(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    def insertLast(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    def deleteFirst(self):
        if self.head:
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            else:
                self.tail = None

    def deleteLast(self):
        if self.tail:
            if self.head == self.tail:
                self.head = None
                self.tail = None
                return
            self.tail = self.tail.prev
            self.tail.next = None

    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False

    def insertAfter(self, u, v):
        curr = self.head
        while curr:
            if curr.val == u:
                new_node = Node(v)
                new_node.next = curr.next
                new_node.prev = curr

                curr.next = new_node
                return
            curr = curr.next
        print(f"Value {u} not found in list.")

    def listSize(self):
        curr = self.head
        size = 0
        while curr:
            curr = curr.next
            size += 1
        return size

    def printList(self):
        curr = self.head
        while curr:
            print(curr.val, end="<->")
            curr = curr.next
        print("None")
