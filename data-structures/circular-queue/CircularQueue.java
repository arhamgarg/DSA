class Node {
  int data;
  Node next;
  public Node(int data) {
    this.data = data;
    this.next = null;
  }
}

public class CircularQueue {
  private Node tail;
  private int size;
  private int maxSize;

  public CircularQueue(int maxSize) {
    this.maxSize = maxSize;
    this.tail = null;
    this.size = 0;
  }

  public void enqueue(int data) {
    if (isFull()) {
      System.out.println("Circular Queue is full!");
      return;
    }
    Node node = new Node(data);
    if (tail == null) {
      tail = node;
      tail.next = tail;
    } else {
      node.next = tail.next;
      tail.next = node;
      tail = node;
    }
    size++;
  }

  public void dequeue() {
    if (isEmpty()) {
      System.out.println("Circular Queue is empty!");
      return;
    }
    if (tail.next == tail) {
      tail = null;
    } else {
      tail.next = tail.next.next;
    }
    size--;
  }

  public int front() {
    if (isEmpty()) {
      System.out.println("Circular Queue is empty!");
      return -1;
    }
    return tail.next.data;
  }

  public int last() {
    if (isEmpty()) {
      System.out.println("Circular Queue is empty!");
      return -1;
    }
    return tail.data;
  }

  public boolean isFull() {
    return size == maxSize;
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public int size() {
    return size;
  }
}
