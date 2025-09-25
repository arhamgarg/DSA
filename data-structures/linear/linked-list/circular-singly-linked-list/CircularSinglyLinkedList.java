public class CircularSinglyLinkedList {
  Node head, tail;

  class Node {
    int data;
    Node next;

    Node(int data) {
      this.data = data;
      this.next = null;
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
  }

  public void display() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    Node currNode = head;

    do {
      System.out.print(currNode.data + " ");
      currNode = currNode.next;
    } while (currNode != head);
    System.out.println();
  }
}
