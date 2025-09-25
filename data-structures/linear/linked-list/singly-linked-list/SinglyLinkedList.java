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

  public void insertAtIndex(int index, int data) {
    if (index < 0 || index >= size) {
      System.out.println("Index should be between 0 and " + (size - 1));
      return;
    }

    if (index == 0) {
      addFront(data);
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

  public void deleteAtIndex(int index) {
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

  public void deleteByValue(int value) {
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
}