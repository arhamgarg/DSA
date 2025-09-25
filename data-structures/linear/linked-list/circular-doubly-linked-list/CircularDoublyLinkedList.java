class CircularDoublyLinkedList {
  Node head, tail;

  class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
      this.data = data;
      this.next = this.prev = null;
    }
  }

  public CircularDoublyLinkedList() {
    tail = null;
    head = null;
  }

  void insertFirst(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = tail = newNode;
      head.next = head;
      head.prev = head;
    } else {
      newNode.next = head;
      newNode.prev = tail;
      head.prev = newNode;
      tail.next = newNode;
      head = newNode;
    }
  }

  void insertLast(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = tail = newNode;
      head.next = head;
      tail.prev = head;
    } else {
      tail.next = newNode;
      newNode.prev = tail;
      newNode.next = head;
      head.prev = newNode;
      tail = newNode;
    }
  }

  public void deleteFirst() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    if (head == tail) {
      head = tail = null;
    } else {
      head = head.next;
      head.prev = tail;
      tail.next = head;
    }
  }

  public void deleteLast() {
    if (tail == null) {
      System.out.println("List is empty");
      return;
    }

    if (head == tail) {
      head = tail = null;
    } else {
      tail = tail.prev;
      tail.next = head;
      head.prev = tail;
    }
  }

  public void displayForward() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    Node currNode = head;
    System.out.print("Forward: ");

    do {
      System.out.print(currNode.data + " ");
      currNode = currNode.next;
    } while (currNode != head);

    System.out.println();
  }

  public void displayBackward() {
    if (tail == null) {
      System.out.println("List is empty");
      return;
    }

    Node currNode = tail;
    System.out.print("Backward: ");

    do {
      System.out.print(currNode.data + " ");
      currNode = currNode.prev;
    } while (currNode != tail);

    System.out.println();
  }
}
