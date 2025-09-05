## python version 3.6 and later since formatted string print is used kindly check that if you are getting error regarding that
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SCL:
    def __init__(self):
        self.head = None
        self.tail = None

# ------------- Core-Operations -------------

    def isEmpty(self):
        print(f"List {'isn\'t' if self.head else 'is'} empty")

    def Traverse(self):
        if self.head is None:
            print("Empty")
            return
        temp = self.head
        while True:
            print(f"{temp.data} -> ", end="")
            temp = temp.next
            if temp == self.head:
                break
        print("(back to head)")

    def front(self):
        if self.head is None:
            print("List empty")
            return -1
        return self.head.data

    def back(self):
        if self.tail is None:
            print("List empty")
            return -1
        return self.tail.data

    def size(self):
        if self.head is None:
            return 0
        count = 0
        temp = self.head
        while True:
            count += 1
            temp = temp.next
            if temp == self.head:
                break
        return count

    def Search(self, search_data):
        if self.head is None:
            print("Empty")
            return
        pos = 0
        temp = self.head
        while True:
            if temp.data == search_data:
                print(f"Data {temp.data} found at position {pos}")
                return
            pos += 1
            temp = temp.next
            if temp == self.head:
                break
        print(f"Data {search_data} not found")

# ------------- Insertions -------------

    def insert_First(self, value):
        new_Node = Node(value)
        if self.head is None:
            self.head = self.tail = new_Node
            new_Node.next = new_Node
        else:
            new_Node.next = self.head
            self.tail.next = new_Node
            self.head = new_Node
        return self.head

    def insert_Last(self, value):
        new_Node = Node(value)
        if self.head is None:
            self.head = self.tail = new_Node
            new_Node.next = new_Node
        else:
            self.tail.next = new_Node
            new_Node.next = self.head
            self.tail = new_Node
        return self.head

    def insert_At(self, position, value):
        if position == 0:
            return self.insert_First(value)

        temp = self.head
        count = 0
        while count < position - 1 and temp.next != self.head:
            temp = temp.next
            count += 1

        if count != position - 1:
            print("Position out of range")
            return self.head

        new_Node = Node(value)
        new_Node.next = temp.next
        temp.next = new_Node

        if temp == self.tail:
            self.tail = new_Node

        return self.head

# ------------- Deletions -------------

    def delete_First(self):
        if self.head is None:
            return None
        if self.head == self.tail:
            print(f"Deleted value : {self.head.data}")
            self.head = self.tail = None
            return None
        temp = self.head
        self.head = self.head.next
        self.tail.next = self.head
        print(f"Deleted value : {temp.data}")
        return self.head

    def delete_Last(self):
        if self.head is None:
            return None
        if self.head == self.tail:
            print(f"Deleted value : {self.head.data}")
            self.head = self.tail = None
            return None
        temp = self.head
        while temp.next != self.tail:
            temp = temp.next
        print(f"Deleted value : {self.tail.data}")
        self.tail = temp
        self.tail.next = self.head
        return self.head

    def delete_At(self, position):
        if self.head is None:
            return None
        if position == 0:
            return self.delete_First()

        temp = self.head
        count = 0
        while count < position - 1 and temp.next != self.head:
            temp = temp.next
            count += 1

        if count != position - 1 or temp.next == self.head:
            print("Position out of range")
            return self.head

        to_Delete = temp.next
        temp.next = to_Delete.next

        if to_Delete == self.tail:
            self.tail = temp

        print(f"Deleted value : {to_Delete.data}")
        return self.head

# ------------- Utilities -------------

    def Update(self, update_val, new_data):
        if self.head is None:
            print("Empty List")
            return None

        temp = self.head
        while True:
            if temp.data == update_val:
                temp.data = new_data
                print(f"Node updated: {update_val} -> {new_data}")
                return self.head
            temp = temp.next
            if temp == self.head:
                break
        print(f"Node with given data: {update_val} not found")
        return self.head


# ---------------- Main ----------------
if __name__ == "__main__":
    list = SCL()

    print("Inserting elements...")
    list.insert_Last(10)
    list.insert_Last(20)
    list.insert_Last(30)
    list.Traverse()

    list.insert_First(5)
    list.Traverse()

    list.insert_At(2, 15)
    list.Traverse()

    print(f"\nFront: {list.front()}")
    print(f"Back : {list.back()}")
    print(f"Size : {list.size()}\n")
##💀💀
    print("Searching for 20...")
    list.Search(20)
    print("Searching for 99...")
    list.Search(99)
    print()

    print("Updating 15 -> 17...")
    list.Update(15, 17)
    list.Traverse()
    print()

    print("Deleting first...")
    list.delete_First()
    list.Traverse()

    print("Deleting last...")
    list.delete_Last()
    list.Traverse()

    print("Deleting at position 1...")
    list.delete_At(1)
    list.Traverse()
    print()

    list.isEmpty()
    print(f"Final size: {list.size()}")
    list.isEmpty()
