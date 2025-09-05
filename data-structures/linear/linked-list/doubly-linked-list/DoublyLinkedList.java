class Node {
  int data;
  Node prev;
  Node next;

  Node(int data) {
    this.data = data;
    this.prev = null;
    this.next = null;
  }
}

public class DoublyLinkedList {
  private Node head, tail;
  private int size;

  public DoublyLinkedList() {
    head = null;
    tail = null;
    size = 0;
  }

  // -------------Core-Operations-------------

  Node Search(int data) {
    Node temp = head;
    int pos = 0;
    while (temp != null) {
      if (temp.data == data) {
        System.out.println("Data " + temp.data + " found at position " + pos);
        return temp;
      }
      pos++;
      temp = temp.next;
    }
    System.out.println("Data " + data + " not found");
    return null;
  }

  public boolean isEmpty() {
    return (size == 0);
  }

  int getAtIndex(int index) {
    Node temp = head;
    int count = 0;
    while (temp != null) {
      if (count == index) {
        return temp.data;
      }
      count++;
      temp = temp.next;
    }
    return -1;
  }

  public int size() {
    return size;
  }

  void TraverseForward() {
    Node current = head;
    System.out.print("Forward: ");
    while (current != null) {
      System.out.print(current.data + " <-> ");
      current = current.next;
    }
    System.out.println();
  }

  void TraverseBackward() {
    Node current = tail;
    System.out.print("Backward: ");
    while (current != null) {
      System.out.print(current.data + " <-> ");
      current = current.prev;
    }
    System.out.println();
  }
  // -------------Insertions-------------

  void insertFirst(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = tail = newNode;
    } else {
      newNode.next = head;
      head.prev = newNode;
      head = newNode;
    }
    size++;
  }

  void insertLast(int data) {
    Node newNode = new Node(data);

    if (tail == null) {
      head = tail = newNode;
    } else {
      tail.next = newNode;
      newNode.prev = tail;
      tail = newNode;
    }
    size++;
  }

  void insertAt(int position, int data) {
    if (position < 0 || position > size) {
      System.out.println("Invalid position\n");
      return;
    }

    if (position == 0) {
      insertFirst(data);
      return;
    }
    if (position == size) {
      insertLast(data);
      return;
    }

    Node temp = head;
    for (int i = 0; i < position - 1; i++) {
      temp = temp.next;
    }

    Node new_Node = new Node(data);
    new_Node.next = temp.next;
    new_Node.prev = temp;
    temp.next.prev = new_Node;
    temp.next = new_Node;

    size++;
  }

  // -------------Deletions-------------
  void deleteFirst() {
    if (head == null) {
      System.out.println(" is Empty");
      return;
    }

    if (head == tail) {
      head = tail = null;
    } else {
      head = head.next;
      head.prev = null;
    }
    size--;
  }

  void deleteLast() {
    if (tail == null) {
      System.out.println(" is Empty");
      return;
    }
    if (head == tail) {
      head = tail = null;
    } else {
      tail = tail.prev;
      tail.next = null;
    }
    size--;
  }

  void deleteAt(int position) {
    if (position < 0 || position >= size) {
      System.out.println("Invalid position");
      return;
    }

    if (position == 0) {
      deleteFirst();
      return;
    }
    if (position == size - 1) {
      deleteLast();
      return;
    }

    Node temp = head;
    for (int i = 0; i < position; i++) {
      temp = temp.next;
    }

    temp.prev.next = temp.next;
    temp.next.prev = temp.prev;

    System.out.println("Deleted value: " + temp.data);
    size--;
  }

  void deleteKey(int delete_data) {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }
    if (head.data == delete_data) {
      deleteFirst();
      return;
    }

    Node temp = Search(delete_data);

    if (temp == null) {
      System.out.println("Data not found");
      return;
    }

    if (temp == tail) {
      deleteLast();
      return;
    }

    temp.prev.next = temp.next;
    temp.next.prev = temp.prev;

    System.out.println("Deleted value: " + temp.data);
    size--;
  }

  // ----------------Utilities----------------
  void update(int old_value, int new_value) {
    Node temp = Search(old_value);
    if (temp != null) {
      System.out.println("Value updated from " + temp.data + " to " + new_value);
      temp.data = new_value;
    } else {
      System.out.println("Value not found");
    }
    return;
  }

  void Reverse() {
    Node curr = head;
    Node temp = null;

    while (curr != null) {
      temp = curr.prev;
      curr.prev = curr.next;
      curr.next = temp;
      curr = curr.prev;
    }

    if (temp != null) {
      head = temp.prev;
    }
  }

  public static void main(String[] args) {
    DoublyLinkedList list = new DoublyLinkedList();

    // Insert elements at the end
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.TraverseForward(); // Forward: 10 <-> 20 <-> 30 <->
    list.TraverseBackward(); // Backward: 30 <-> 20 <-> 10 <->

    // Insert at the beginning
    list.insertFirst(5);
    list.TraverseForward(); // Forward: 5 <-> 10 <-> 20 <-> 30 <->

    // Insert at specific positions
    list.insertAt(2, 15);
    list.TraverseForward(); // Forward: 5 <-> 10 <-> 15 <-> 20 <-> 30 <->
    list.insertAt(3, 18);
    list.TraverseForward(); // Forward: 5 <-> 10 <-> 15 <-> 18 <-> 20 <-> 30 <->

    // Core operations
    System.out.println("Size: " + list.size()); // Size: 6
    System.out.println("Get(2): " + list.getAtIndex(2)); // Get(2): 15

    // Update node value
    list.update(15, 16);
    list.TraverseForward(); // Forward: 5 <-> 10 <-> 16 <-> 18 <-> 20 <-> 30 <->

    // Deletions
    list.deleteFirst();
    list.TraverseForward(); // Forward: 10 <-> 16 <-> 18 <-> 20 <-> 30 <->

    list.deleteLast();
    list.TraverseForward(); // Forward: 10 <-> 16 <-> 18 <-> 20 <->

    list.deleteAt(1);
    list.TraverseForward(); // Forward: 10 <-> 18 <-> 20 <->

    list.deleteKey(18);
    list.TraverseForward(); // Forward: 10 <-> 20 <->

    // Reverse list
    list.Reverse();
    list.TraverseForward(); // Forward: 20 <-> 10 <->

    // Add more values
    list.insertLast(25);
    list.insertLast(35);
    list.TraverseForward(); // Forward: 20 <-> 10 <-> 25 <-> 35 <->
    list.TraverseBackward(); // Backward: 35 <-> 25 <-> 10 <-> 20 <->

    // Search example
    list.Search(25); // Data 25 found at position 2
    list.Search(99); // Data 99 not found
  }

}
