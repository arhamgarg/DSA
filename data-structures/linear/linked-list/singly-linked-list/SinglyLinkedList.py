## python version 3.6 and later since formatted string print is used kindly check that if you are getting error regarding that
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    # --------------Core operations--------------

    def getSize(self):
        return self.size

    def Traverse(self):
        temp = self.head
        while temp is not None:
            print(f"{temp.data} -> ", end="")
            temp = temp.next
        print("NULL")

    def Update(self, update_val, new_data):
        temp = self.head
        while temp is not None and temp.data != update_val:
            temp = temp.next
        if temp is None:
            print(f"Node with given data: {update_val} not found")
            return
        temp.data = new_data

    def Search(self, search_data):
        temp = self.head
        pos = 0
        while temp is not None:
            if temp.data == search_data:
                print(f"Data {search_data} found at position {pos}")
                return
            temp = temp.next
            pos += 1
        print(f"Data {search_data} not found")

    def getAtIndex(self, index):
        idx = 0
        temp = self.head
        while temp is not None:
            if idx == index:
                return temp.data
            temp = temp.next
            idx += 1
        print("Index out of range")
        return -1

    def isEmpty(self):
        print("List isn't empty" if self.head else "List is empty")

    # --------------Insertion--------------

    def insertFirst(self, value):
        new_node = Node(value)
        new_node.next = self.head
        self.head = new_node
        self.size += 1

    def insertLast(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.next = new_node
        self.size += 1

    def insertAt(self, position, value):
        if position == 0:
            self.insertFirst(value)
            return

        temp = self.head
        for _ in range(position - 1):
            if temp is None:
                break
            temp = temp.next

        if temp is None:
            print("Position out of range")
            return

        new_node = Node(value)
        new_node.next = temp.next
        temp.next = new_node
        self.size += 1

    def insertAfter(self, node_Data, data):
        temp = self.head
        while temp is not None and temp.data != node_Data:
            temp = temp.next

        if temp is None:
            print(f"Node with given data: {node_Data} not found")
            return

        new_node = Node(data)
        new_node.next = temp.next
        temp.next = new_node
        self.size += 1

    # --------------Deletions--------------

    def deleteFirst(self):
        if self.head is None:
            return
        print(f"Deleted value: {self.head.data}")
        self.head = self.head.next
        self.size -= 1

    def deleteLast(self):
        if self.head is None:
            return
        if self.head.next is None:
            print(f"Deleted value: {self.head.data}")
            self.head = None
            self.size -= 1
            return
        temp = self.head
        while temp.next.next is not None:
            temp = temp.next
        print(f"Deleted value: {temp.next.data}")
        temp.next = None
        self.size -= 1

    def deleteAt(self, position):
        if self.head is None:
            return
        if position == 0:
            self.deleteFirst()
            return

        temp = self.head
        for _ in range(position - 1):
            if temp.next is None:
                break
            temp = temp.next

        if temp.next is None:
            print("Position out of range")
            return

        print(f"Deleted value: {temp.next.data}")
        temp.next = temp.next.next
        self.size -= 1

    def deleteKey(self, delete_data):
        if self.head is None:
            return
        if self.head.data == delete_data:
            print(f"Deleted value: {self.head.data}")
            self.head = self.head.next
            self.size -= 1
            return

        prev = self.head
        curr = self.head.next

        while curr is not None and curr.data != delete_data:
            prev = curr
            curr = curr.next

        if curr is None:
            print(f"Node with given data: {delete_data} not found")
            return

        print(f"Deleted value: {curr.data}")
        prev.next = curr.next
        self.size -= 1

    # --------------Utilities--------------

    def Reverse(self):
        prev_node = None
        current = self.head
        while current is not None:
            next_node = current.next
            current.next = prev_node
            prev_node = current
            current = next_node
        self.head = prev_node

    def front(self):
        if self.head is None:
            print("List empty")
            return -1
        return self.head.data

    def last(self):
        if self.head is None:
            print("List empty")
            return -1
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        return temp.data

    def findMiddle(self):
        if self.head is None:
            print("List is empty")
            return
        slow = self.head
        fast = self.head
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        print(f"The middle value is: {slow.data}")


# --------------Test--------------

if __name__ == "__main__":
    list = SinglyLinkedList() ##credits: Nanthana-kenhgk for all base python code

    list.insertLast(10)
    list.insertLast(20)
    list.insertLast(30)
    list.Traverse()

    list.insertFirst(5)
    list.Traverse()

    list.insertAt(2, 15)
    list.Traverse()

    list.insertAfter(15, 18)
    list.Traverse()

    print("Front:", list.front())
    print("Last:", list.last())
    print("Size:", list.getSize())
    print("Get(2):", list.getAtIndex(2))

    list.Update(15, 16)
    list.Traverse()

    list.deleteFirst()
    list.Traverse()

    list.deleteLast()
    list.Traverse()

    list.deleteAt(1)
    list.Traverse()

    list.deleteKey(18)
    list.Traverse()

    list.Reverse()
    list.Traverse()

    list.insertLast(25)
    list.insertLast(35)
    list.Traverse()
    list.findMiddle()
    list.isEmpty()
