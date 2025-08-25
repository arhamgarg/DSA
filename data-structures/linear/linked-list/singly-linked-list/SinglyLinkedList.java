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

  public void addFront(int data) {
    Node newNode = new Node(data);
    newNode.next = head;
    head = newNode;
    size++;
  }

  public void addLast(int data) {
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

  public int size() {
    return size;
  }
}
