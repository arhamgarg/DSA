## python version 3.6 and later since formatted string print is used kindly check that if you are getting error regarding that
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DCL:
    def __init__(self):
        self.head = None
        self.tail = None

    # ------------- Core Operations -------------
    def TraverseForward(self):
        if self.head is None:
            print("Empty")
            return
        temp = self.head
        while True:
            print(f"{temp.data} <-> ", end="")
            temp = temp.next
            if temp == self.head:
                break
        print("(back to head)")

    def TraverseBackward(self):
        if self.head is None:
            print("Empty")
            return
        temp = self.tail
        while True:
            print(f"{temp.data} <-> ", end="")
            temp = temp.prev
            if temp == self.tail:
                break
        print("(back to tail)")

    def isEmpty(self):
        print("List isn't empty" if self.head else "List is empty")

    def Search(self, search_data):  # 😎📔
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

    # ------------- Insertions -------------
    def insert_First(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = self.tail = new_node
            new_node.next = new_node.prev = new_node
        else:
            new_node.next = self.head
            new_node.prev = self.tail
            self.tail.next = new_node
            self.head.prev = new_node
            self.head = new_node
        return self.head

    def insert_Last(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = self.tail = new_node
            new_node.next = new_node.prev = new_node
        else:
            new_node.prev = self.tail
            new_node.next = self.head
            self.tail.next = new_node
            self.head.prev = new_node
            self.tail = new_node
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

        new_node = Node(value)
        new_node.next = temp.next
        new_node.prev = temp
        temp.next.prev = new_node
        temp.next = new_node

        if temp == self.tail:
            self.tail = new_node

        return self.head

    # ------------- Deletions -------------
    def delete_First(self):
        if self.head is None:
            return None
        temp = self.head
        if self.head == self.tail:
            print(f"Deleted value : {temp.data}")
            self.head = self.tail = None
            return None
        print(f"Deleted value : {temp.data}")
        self.head = self.head.next
        self.tail.next = self.head
        self.head.prev = self.tail
        return self.head

    def delete_Last(self):
        if self.head is None:
            return None
        temp = self.tail
        if self.head == self.tail:
            print(f"Deleted value : {temp.data}")
            self.head = self.tail = None
            return None
        print(f"Deleted value : {temp.data}")
        self.tail = self.tail.prev
        self.tail.next = self.head
        self.head.prev = self.tail
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

        to_delete = temp.next
        print(f"Deleted: {to_delete.data}")

        temp.next = to_delete.next
        to_delete.next.prev = temp

        if to_delete == self.tail:
            self.tail = temp

        return self.head

    def deleteKey(self, delete_data):
        if self.head is None:
            return None
        temp = self.head
        while True:
            if temp.data == delete_data:
                if temp == self.head and temp == self.tail:
                    print(f"Deleted value: {temp.data}")
                    self.head = self.tail = None
                    return None
                elif temp == self.head:
                    return self.delete_First()
                elif temp == self.tail:
                    return self.delete_Last()
                else:
                    temp.prev.next = temp.next
                    temp.next.prev = temp.prev
                    print(f"Deleted value: {temp.data}")
                    return self.head
            temp = temp.next
            if temp == self.head:
                break
        print(f"Node with given data: {delete_data} not found")
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

    def Reverse(self):
        if self.head is None:
            print("Empty List")
            return None
        current = self.head
        temp = None
        while True:
            temp = current.prev
            current.prev = current.next
            current.next = temp
            current = current.prev
            if current == self.head:
                break
        temp = self.head
        self.head = self.tail
        self.tail = temp
        return self.head


# ---------------- Test ----------------
if __name__ == "__main__":
    list = DCL()

    list.insert_Last(10)
    list.insert_Last(20)
    list.insert_Last(30)
    list.TraverseForward()

    list.insert_First(5)
    list.TraverseForward()

    list.insert_At(2, 15)
    list.TraverseForward()

    print("Front:", list.front())
    print("Back:", list.back())
    print("Size:", list.size())
#😎📔
    list.delete_First()
    list.TraverseForward()

    list.delete_Last()
    list.TraverseForward()

    list.delete_At(1)
    list.TraverseForward()

    list.deleteKey(15)
    list.TraverseForward()

    list.Update(20, 200)
    list.TraverseForward()

    list.Reverse()
    list.TraverseForward()
    list.TraverseBackward()
