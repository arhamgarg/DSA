class DoubleyLinkedList {
  Node head, tail;

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

  public DoubleyLinkedList() {
    head = null;
    tail = null;
  }

  void insertFirst(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = tail = newNode;
    } else {
      newNode.next = head;
      head.prev = newNode;
      head = newNode;
    }
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
  }

  void deleteFirst() {
    if (head == null) {
      System.out.println("Lsit is Empty");
      return;
    }

    if (head == tail) {
      head = tail = null;
    } else {
      head = head.next;
      head.prev = null;
    }
  }

  void deleteLast() {
    if (tail == null) {
      System.out.println("List is Empty");
      return;
    }
    if (head == tail) {
      head = tail = null;
    } else {
      tail = tail.prev;
      tail.next = null;
    }
  }

  void displayForward() {
    Node current = head;
    System.out.print("Forward: ");
    while (current != null) {
      System.out.print(current.data + " ");
      current = current.next;
    }
    System.out.println();
  }

  void displayBackward() {
    Node current = tail;
    System.out.print("Backward: ");
    while (current != null) {
      System.out.print(current.data + " ");
      current = current.prev;
    }
    System.out.println();
  }
}
