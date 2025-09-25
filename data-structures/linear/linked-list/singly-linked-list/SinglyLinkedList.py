class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert_first(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node

    def insert_last(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            return
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = new_node

    def delete_first(self):
        if self.head:
            self.head = self.head.next

    def delete_last(self):
        if not self.head:
            return
        if not self.head.next:
            self.head = None
            return
        curr = self.head
        while curr.next and curr.next.next:
            curr = curr.next
        curr.next = None

    def insert_after(self, target, value):
        curr = self.head
        while curr:
            if curr.value == target:
                new_node = Node(value)
                new_node.next = curr.next
                curr.next = new_node
                return
            curr = curr.next
        raise ValueError(f"Value {target} not found in list.")

    def is_empty(self):
        return self.head is None

    def printList(self):
        curr = self.head
        while curr:
            print(curr.val, end="->")
            curr = curr.next
        print("None")

    def size(self):
        count = 0
        curr = self.head
        while curr:
            count += 1
            curr = curr.next
        return count
