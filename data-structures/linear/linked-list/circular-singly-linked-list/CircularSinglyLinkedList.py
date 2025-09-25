class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class CircularSinglyLinkedList:
    def __init__(self):
        self.head = None

    def insertFirst(self, val):
        new_node = Node(val)
        if self.head is None:
            new_node.next = new_node
            self.head = new_node
        else:
            curr = self.head
            while curr.next != self.head:
                curr = curr.next
            new_node.next = self.head
            curr.next = new_node
            self.head = new_node

    def insertLast(self, val):
        new_node = Node(val)
        if self.head is None:
            new_node.next = new_node
            self.head = new_node
        else:
            curr = self.head
            while curr.next != self.head:
                curr = curr.next
            curr.next = new_node
            new_node.next = self.head

    def deleteFirst(self):
        if self.head is None:
            return
        if self.head.next == self.head:
            self.head = None
        else:
            curr = self.head
            while curr.next != self.head:
                curr = curr.next
            curr.next = self.head.next
            self.head = self.head.next

    def deleteLast(self):
        if self.head is None:
            return
        if self.head.next == self.head:
            self.head = None
        else:
            prev = None
            curr = self.head
            while curr.next != self.head:
                prev = curr
                curr = curr.next
            prev.next = self.head

    def insertAfter(self, u, v):
        if self.head is None:
            print(f"Value {u} not found in list.")
            return
        curr = self.head
        while True:
            if curr.val == u:
                new_node = Node(v)
                new_node.next = curr.next
                curr.next = new_node
                return
            curr = curr.next
            if curr == self.head:
                break
        print(f"Value {u} not found in list.")

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
            print(curr.val, end="->")
            curr = curr.next
            if curr == self.head:
                break
        print("(back to head)")
