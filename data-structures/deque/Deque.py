class Deque:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return len(self.items) == 0

    def insertFront(self, item):
        self.items.insert(0, item)
        print(f"Inserted at front: {item}")

    def insertRear(self, item):
        self.items.append(item)
        print(f"Inserted at rear: {item}")

    def deleteFront(self):
        if self.isEmpty():
            print("Deque is empty! Cannot delete from front.")
            return None
        removed = self.items.pop(0)
        print(f"Deleted from front: {removed}")
        return removed

    def deleteRear(self):
        if self.isEmpty():
            print("Deque is empty! Cannot delete from rear.")
            return None
        removed = self.items.pop()
        print(f"Deleted from rear: {removed}")
        return removed

    def getFront(self):
        if self.isEmpty():
            print("Deque is empty!")
            return None
        return self.items[0]

    def getRear(self):
        if self.isEmpty():
            print("Deque is empty!")
            return None
        return self.items[-1]

    def size(self):
        return len(self.items)

    def display(self):
        print("Deque contents:", self.items)
