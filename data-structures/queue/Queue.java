public class Queue {
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

  public void enqueue(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = newNode;
      size++;
      return;
    }

    Node currNode = head;
    while (currNode.next != null) {
      currNode = currNode.next;
    }

    currNode.next = newNode;
    size++;
  }

  public int dequeue() {
    if (head == null) {
      System.out.println("Queue is empty");
      return -1;
    }
    int value = head.data;
    size--;
    head = head.next;
    return value;
  }

  public int front() {
    if (head == null) {
      System.out.println("Queue is empty");
    }
    return head.data;
  }

  public int size() {
    return size;
  }

  public boolean isEmpty() {
    return size == 0;
  }
}
