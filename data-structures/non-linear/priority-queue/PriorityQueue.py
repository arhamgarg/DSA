class Node:
    def __init__(self, data, priority):
        self.data = data
        self.priority = priority
        self.next = None

class PriorityQueue:
    def __init__(self):
        self.head = None
        self.size=0

    def insert_item(self, data, priority):
        new_node = Node(data, priority)

        if not self.head or self.head.priority > priority:
            new_node.next = self.head
            self.head = new_node
        else:
            current = self.head
            while current.next and current.next.priority <= priority:
                current = current.next
            new_node.next = current.next
            current.next = new_node
        self.size+=1

    def remove_min(self):
        if not self.head:
            return None
        item = self.head.data
        self.head = self.head.next
        self.size-=1
        return item

    def min_element(self):
        return None if not self.head else self.head.data
    
    def min_key(self):
        return None if not self.head else self.head.priority
    
    def _size(self):
        return self.size
    
    def is_empty(self):
        return self.size==0