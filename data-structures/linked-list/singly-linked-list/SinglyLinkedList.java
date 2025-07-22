public class SinglyLinkedList {
  Node head;
  private int size;

  class Node {
    int data;
    Node next;

    Node(int data) {
      this.data = data;
      this.next = null;
    }
  }

  public SinglyLinkedList() {
    head = null;
  }

  public void AddFront(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = newNode;
      size++;
      return;
    }

    newNode.next = head;
    head = newNode;
    size++;
  }

  public void AddLast(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = newNode;
      return;
    }

    Node currNode = head;
    while (currNode.next != null) {
      currNode = currNode.next;
    }

    currNode.next = newNode;
    size++;
  }

  public boolean Search(int value) {
    Node currNode = head;

    while (currNode != null) {
      if (currNode.data == value) {
        return true;
      }
      currNode = currNode.next;
    }
    return false;
  }

  public void PrintList() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }

    Node currNode = head;

    while (currNode != null) {
      System.out.print(currNode.data + "-->");
      currNode = currNode.next;
    }

    System.out.println("NULL");
  }

  public void DeleteFirst() {
    if (head == null) {
      System.out.println("List is empty");
      return;
    }
    size--;
    head = head.next;
  }

  public void DeleteLast() {
    if (head == null) {
      System.out.println("Lsit is empty");
      return;
    }

    if (head.next == null) {
      head = null;
      return;
    }

    Node secondLast = head;
    Node lastNode = head.next;

    while (lastNode.next != null) {
      lastNode = lastNode.next;
      secondLast = secondLast.next;
    }

    size--;
    secondLast.next = null;
  }

  public int size() {
    return size;
  }
}
