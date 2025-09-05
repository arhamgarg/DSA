public class CircularSinglyLinkedList {
  Node head, tail;
  int size = 0;

  class Node {
    int data;
    Node next;

    Node(int data) {
      this.data = data;
      this.next = null;
    }
  }

  // ----------------Core-Operations----------------
  boolean isEmpty() {
    return (size == 0);
  }

  int size() {
    return size;
  }

  void Traverse() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    Node currNode = head;

    do {
      System.out.print(currNode.data + " -> ");
      currNode = currNode.next;
    } while (currNode != head);
    System.out.println("(back to head)");
  }

  Node Search(int search_value) {
    if (isEmpty())
      return null;
    else {
      Node temp = head;
      int pos = 0;
      do {
        if (temp.data == search_value) {
          System.out.println("Data " + temp.data + " found at position " + pos);
          return temp;
        }
        temp = temp.next;
        pos++;
      } while (temp != head);
      if (temp == head)
        System.out.println("Data not found");
      return null;
    }
  }

  void insertFirst(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = tail = newNode;
      return;
    }

    newNode.next = head;
    head = newNode;
    tail.next = head;
    size++;
  }

  void insertLast(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = tail = newNode;
      return;
    }

    tail.next = newNode;
    tail = newNode;
    tail.next = head;
    size++;
  }

  void insertAt(int position, int value) {
    if (position == 0) {
      insertFirst(value);
      return;
    }

    Node temp = head;
    int count = 0;
    while (count < position - 1 && temp.next != head) {
      temp = temp.next;
      count++;
    }

    if (count != position - 1) {
      System.out.println("Position out of range");
      return;
    }

    Node new_Node = new Node(value);
    new_Node.next = temp.next;
    temp.next = new_Node;

    if (temp == tail) { // inserted at the end
      tail = new_Node;
    }
    size++;
  }

  public void deleteFirst() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    if (head == tail) {
      head = tail = null;
    }
    head = head.next;
    tail.next = head;
    size--;
  }

  public void deleteLast() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    if (head == tail) {
      head = tail = null;
    }

    Node currNode = head;
    while (currNode.next != tail) {
      currNode = currNode.next;
    }
    tail = currNode;
    tail.next = head;
    size--;
  }

  void delete_At(int position) {
    if (head == null)
      return;
    if (position == 0) {
      deleteFirst();
      return;
    }

    Node temp = head;
    int count = 0;
    while (count < position - 1 && temp.next != head) {
      temp = temp.next;
      count++;
    }

    if (count != position - 1 || temp.next == head) {
      System.out.println("Position out of range");
      return;
    }

    Node to_Delete = temp.next;
    temp.next = to_Delete.next;

    if (to_Delete == tail) {
      tail = temp;
    }

    System.out.println("Deleted value : " + to_Delete.data);
    size--;
  }

  // -------------Utilities-------------

  void Update(int update_val, int new_data) {
    if (head == null) {
      System.out.println("Empty List");
      return;
    }

    Node temp = head;
    boolean found = false;
    do {
      if (temp.data == update_val) {
        temp.data = new_data;
        System.out.println("Node updated: " + update_val + " to " + new_data);
        found = true;
        break;
      }
      temp = temp.next;
    } while (!found);
    System.out.println("Node with given data: " + update_val + " not found");
  }

  void findMiddle() {
    if (head == null) {
      System.out.println("List is Empty");
      return;
    }
    Node fast = head;
    Node slow = head;
    while (fast.next != head && fast.next.next != head) {
      fast = fast.next.next;
      slow = slow.next;
    }
    System.out.println("The middle value is: " + slow.data);
  }

  public static void main(String[] args) {
    CircularSinglyLinkedList list = new CircularSinglyLinkedList();

    // Insert at last
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.Traverse(); // 10 -> 20 -> 30 -> (back to head)

    // Insert at first
    list.insertFirst(5);
    list.Traverse(); // 5 -> 10 -> 20 -> 30 -> (back to head)

    // Insert at specific index
    list.insertAt(2, 15);
    list.Traverse(); // 5 -> 10 -> 15 -> 20 -> 30 -> (back to head)

    list.insertAt(3, 18);
    list.Traverse(); // 5 -> 10 -> 15 -> 18 -> 20 -> 30 -> (back to head)

    // Core operations
    System.out.println("Size: " + list.size());
    list.Search(15); // Found
    list.Search(100); // Not found

    // Update
    list.Update(15, 16);
    list.Traverse(); // 5 -> 10 -> 16 -> 18 -> 20 -> 30 -> (back to head)

    // Deletions
    list.deleteFirst();
    list.Traverse(); // 10 -> 16 -> 18 -> 20 -> 30 -> (back to head)

    list.deleteLast();
    list.Traverse(); // 10 -> 16 -> 18 -> 20 -> (back to head)

    list.delete_At(1);
    list.Traverse(); // 10 -> 18 -> 20 -> (back to head)

    // Delete by value (simulate manually)
    list.delete_At(1); // deleting "18"
    list.Traverse(); // 10 -> 20 -> (back to head)

    // Find middle
    list.findMiddle(); // Middle is 10 or 20 depending on count
  }

}
