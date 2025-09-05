class Node {
  int data;
  Node next;

  Node(int data) {
    this.data = data;
    this.next = null;
  }
}

public class SinglyLinkedList {
  private Node head;
  private int size;

  public SinglyLinkedList() {
    head = null;
    size = 0;
  }

  // -------------Core-Operations-------------
  public boolean isEmpty() {
    return (size == 0);
  }

  public int size() {
    return size;
  }

  public int getAtIndex(int index) {
    int index_counter = 0;
    Node temp = head;
    while (temp != null) {
      if (index == index_counter)
        return temp.data;
      temp = temp.next;
      index_counter++;
    }
    return -1;
  }

  public boolean search(int value) {
    Node curr = head;

    while (curr != null) {
      if (curr.data == value) {
        return true;
      }

      curr = curr.next;
    }

    return false;
  }

  public void Traverse() {
    Node curr = head;
    while (curr != null) {
      System.out.print(curr.data);
      if (curr.next != null)
        System.out.print(" -> ");
      curr = curr.next;
    }
    System.out.println("NULL");
  }

  // -------------Insertions-------------

  public void insertFront(int data) {
    Node newNode = new Node(data);

    newNode.next = head;
    head = newNode;
    size++;
  }

  public void insertLast(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = newNode;
    } else {
      Node curr = head;

      while (curr.next != null) {
        curr = curr.next;
      }

      curr.next = newNode;
    }

    size++;
  }

  public void insertAtIndex(int index, int data) {
    if (index < 0 || index > size) {
      System.out.println("Index should be between 0 and " + (size - 1));
      return;
    }

    if (index == 0) {
      insertFront(data);
      return;
    }

    Node newNode = new Node(data);
    Node currNode = head;

    for (int i = 0; i < index - 1; i++) {
      currNode = currNode.next;
    }

    newNode.next = currNode.next;
    currNode.next = newNode;
    size++;
  }

  // -------------Deletions-------------

  public void deleteFirst() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    head = head.next;
    size--;
  }

  public void deleteLast() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    if (head.next == null) {
      head = null;
    } else {
      Node curr = head;

      while (curr.next.next != null) {
        curr = curr.next;
      }

      curr.next = null;
    }

    size--;
  }

  public void deleteAt(int index) {
    if (index < 0 || index >= size) {
      System.out.println("Index should be between 0 and " + (size - 1));
      return;
    }

    if (index == 0) {
      deleteFirst();
      return;
    }

    Node currNode = head;

    for (int i = 0; i < index - 1; i++) {
      currNode = currNode.next;
    }

    currNode.next = currNode.next.next;
    size--;
  }

  public void deleteKey(int value) {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    if (head.data == value) {
      head = head.next;
      size--;
      return;
    }

    Node currNode = head;

    while (currNode.next != null && currNode.next.data != value) {
      currNode = currNode.next;
    }

    if (currNode.next == null) {
      System.out.println("Value " + value + " is not found in the list");
      return;
    }

    currNode.next = currNode.next.next;
    size--;
  }
  // -------------Utilities-------------

  public void Update(int update_val, int new_data) {
    Node temp = head;
    while (temp != null && temp.data != update_val) {
      temp = temp.next;
    }
    if (temp == null) {
      System.out.println("Node with given data: " + update_val + " not found");
      return;
    }
    temp.data = new_data;
    System.out.println("Data updated from " + update_val + " to " + new_data);
  }

  public void findMiddle() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }
    Node fast = head;
    Node slow = head;
    while (fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next.next;
    }
    System.out.println("The middle value is: " + slow.data);
  }

  public void Reverse() {
    if (head == null)
      return;
    Node prev_Node = null;
    Node current_Node = head;
    Node next_Node = null;

    while (current_Node != null) {
      next_Node = current_Node.next;
      current_Node.next = prev_Node;
      prev_Node = current_Node;
      current_Node = next_Node;
    }
    head = prev_Node;
  }

  public static void main(String[] args) {
    SinglyLinkedList list = new SinglyLinkedList();

    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.Traverse(); // 10 -> 20 -> 30 -> NULL

    list.insertFront(5);
    list.Traverse(); // 5 -> 10 -> 20 -> 30 -> NULL

    list.insertAtIndex(2, 15);
    list.Traverse(); // 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    list.insertAtIndex(3, 18);
    list.Traverse(); // 5 -> 10 -> 15 -> 18 -> 20 -> 30 -> NULL

    System.out.println("Size: " + list.size());
    System.out.println("Get(2): " + list.getAtIndex(2));

    list.Update(15, 16);
    list.Traverse(); // 5 -> 10 -> 16 -> 18 -> 20 -> 30 -> NULL

    list.deleteFirst();
    list.Traverse(); // 10 -> 16 -> 18 -> 20 -> 30 -> NULL

    list.deleteLast();
    list.Traverse(); // 10 -> 16 -> 18 -> 20 -> NULL

    list.deleteAt(1);
    list.Traverse(); // 10 -> 18 -> 20 -> NULL

    list.deleteKey(18);
    list.Traverse(); // 10 -> 20 -> NULL

    list.Reverse();
    list.Traverse(); // 20 -> 10 -> NULL

    list.insertLast(25);
    list.insertLast(35);
    list.Traverse(); // 20 -> 10 -> 25 -> 35 -> NULL

    list.findMiddle(); // prints "The middle value is: 10" or "25"
  }

}