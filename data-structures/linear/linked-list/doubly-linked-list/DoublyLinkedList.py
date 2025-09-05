## python version 3.6 and later since formatted string print is used kindly check that if you are getting error regarding that
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    # ---------------- Insert Operations ----------------
    def insertFirst(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = self.tail = new_node
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
        self.size += 1

    def insertLast(self, value):
        new_node = Node(value)
        if self.tail is None:
            self.head = self.tail = new_node
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def insertAt(self, position, value):
        if position < 0 or position > self.size:
            print("Invalid position")
            return

        if position == 0:
            self.insertFirst(value)
            return
        if position == self.size:
            self.insertLast(value)
            return

        temp = self.head
        for _ in range(position - 1):
            temp = temp.next

        new_node = Node(value)
        new_node.next = temp.next
        new_node.prev = temp
        temp.next.prev = new_node
        temp.next = new_node

        self.size += 1

    # ---------------- Delete Operations ----------------
    def deleteFirst(self):
        if self.head is None:
            return
        temp = self.head
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        print(f"Deleted value: {temp.data}")
        self.size -= 1

    def deleteLast(self):
        if self.tail is None:
            return
        temp = self.tail
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        print(f"Deleted value: {temp.data}")
        self.size -= 1

    def deleteAt(self, position):
        if position < 0 or position >= self.size:
            print("Invalid position")
            return

        if position == 0:
            self.deleteFirst()
            return
        if position == self.size - 1:
            self.deleteLast()
            return

        temp = self.head
        for _ in range(position):
            temp = temp.next

        temp.prev.next = temp.next
        temp.next.prev = temp.prev
        print(f"Deleted value: {temp.data}")
        self.size -= 1

    def deleteKey(self, delete_data):
        if self.head is None:
            return

        if self.head.data == delete_data:
            self.deleteFirst()
            return

        temp = self.head
        while temp is not None and temp.data != delete_data:
            temp = temp.next

        if temp is None:
            print("Data not found")
            return

        if temp == self.tail:
            self.deleteLast()
            return

        temp.prev.next = temp.next
        temp.next.prev = temp.prev
        print(f"Deleted value: {temp.data}")
        self.size -= 1

    # ---------------- Search ----------------
    def search(self, value):
        temp = self.head
        while temp is not None:
            if temp.data == value:
                return temp
            temp = temp.next
        return None

    # ---------------- Update ----------------
    def update(self, old_value, new_value):
        temp = self.search(old_value)
        if temp is not None:
            temp.data = new_value
            return temp
        print("Value not found")
        return None

    # ---------------- Reverse ----------------
    def Reverse(self):
        curr = self.head
        prev_node = None

        while curr is not None:
            prev_node = curr.prev
            curr.prev = curr.next
            curr.next = prev_node
            curr = curr.prev

        if prev_node is not None:
            self.head = prev_node.prev

        # swap head and tail
        self.head, self.tail = self.tail, self.head

    # ---------------- Utilities ----------------
    def traverseForward(self):
        temp = self.head
        while temp is not None:
            print(f"{temp.data} <-> ", end="")
            temp = temp.next
        print("NULL")

    def traverseBackward(self):
        temp = self.tail
        while temp is not None:
            print(f"{temp.data} <-> ", end="")
            temp = temp.prev
        print("NULL")

    def isEmpty(self):
        print("List is empty" if self.head is None else "List isn't empty")

    def getSize(self):
        return self.size


# ---------------- Test ----------------
if __name__ == "__main__":
    list = DoublyLinkedList()

    # Inserts
    list.insertFirst(10)
    list.insertFirst(20)
    list.insertLast(30)
    list.insertAt(1, 15)

    print("Forward traversal: ", end="")
    list.traverseForward()
    print("Backward traversal: ", end="")
    list.traverseBackward()

    # Deletes
    list.deleteFirst()
    list.deleteLast()
    list.deleteAt(1)
    list.deleteKey(10)

    print("After deletions (forward): ", end="")
    list.traverseForward()

    # Search & Update
    list.insertLast(40)
    list.insertLast(50)
    found = list.search(40)
    if found:
        print(f"Found: {found.data}")
    list.update(50, 60)

    print("After update (forward): ", end="")
    list.traverseForward()

    # Reverse
    list.Reverse()
    print("After reverse (forward): ", end="")
    list.traverseForward()

    # Utilities
    list.isEmpty()
    print("Size of list:", list.getSize())
