public class Node {
  int data;
  Node next;

  public Node(int data) {
    this.data = data;
    this.next = null;
  }
}

public class Queue {
  private Node head;
  private int size;

  public Queue() {
    head = null;
    size = 0;
  }

  public void enqueue(int data) {
    Node newNode = new Node(data);

    if (head == null) {
      head = newNode;
      size++;
      return;
    }

    Node curr = head;

    while (curr.next != null) {
      curr = curr.next;
    }

    curr.next = newNode;
    size++;
  }

  public void dequeue() {
    if (head == null) {
      System.out.println("Queue is empty");
    }

    head = head.next;
    size--;
  }

  public int front() {
    if (head == null) {
      System.out.println("Queue is empty");
    }

    return head.data;
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public int size() {
    return size;
  }
}
