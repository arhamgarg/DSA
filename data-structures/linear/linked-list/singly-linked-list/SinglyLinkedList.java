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

  public void InsertAtIndex(int index, int data) {
    if (index < 0 || index > size) {
      System.out.println("Index should be between 0 and " + size);
      return;
    }

    if (index == 0) {
      AddFront(data);
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


  public void DeleteByValue(int value) {
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
      System.out.println("Value " + value + " not found in the list");
      return;
    }

    currNode.next = currNode.next.next;
    size--;
  }


  public void DeleteAtIndex(int index) {
    if (index < 0 || index >= size) {
      System.out.println("Index should be between 0 and " + (size - 1));
      return;
    }

    if (index == 0) {
      DeleteFirst();
      return;
    }

    Node currNode = head;
    for (int i = 0; i < index - 1; i++) {
      currNode = currNode.next;
    }

    currNode.next = currNode.next.next;
    size--;
  }
  
}
