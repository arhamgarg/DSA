class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insertFirst(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            return
        new_node.next = self.head
        self.head = new_node

    def insertLast(self, val):
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = new_node

    def deleteFirst(self):
        if self.head:
            self.head = self.head.next

    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False

    def deleteLast(self):
        if self.head is None:
            return
        if self.head.next is None:
            self.head = None
            return
        prev = None
        curr = self.head
        while curr.next:
            prev = curr
            curr = curr.next
        prev.next = None

    def insertAfter(self, u, v):
        curr = self.head
        while curr:
            if curr.val == u:
                new_node = Node(v)
                new_node.next = curr.next
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
            print(curr.val, end="->")
            curr = curr.next
        print("None")
