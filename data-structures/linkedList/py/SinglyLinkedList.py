class SinglyNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self.val)


head = SinglyNode(1)

# Traverse the list - O(n)
curr = head

while curr:
    print(curr)
    curr = curr.next


# Diplay linked list - O(n)
def display(head):
    curr = head
    elements = []
    while curr:
        elements.append(str(curr.val))
        curr = curr.next
    print(" -> ".join(elements))


# Search for node value - O(n)
def search(head, val):
    curr = head
    while curr:
        if val == curr.val:
            return True
        curr = curr.next

    return False
