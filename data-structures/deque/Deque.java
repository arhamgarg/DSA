public class Deque {
  Node front, rear;

  class Node {
    int data;
    Node next;
    Node prev;

    public Node(int data) {
      this.data = data;
      this.next = null;
      this.prev = null;
    }
  }

  public Deque() {
    front = rear = null;
  }

  public void addFront(int data) {
    Node newNode = new Node(data);
    if (isEmpty()) {
      front = rear = newNode;
    } else {
      newNode.next = front;
      front.prev = newNode;
      front = newNode;
    }
  }

  public void addRear(int data) {
    Node newNode = new Node(data);
    if (isEmpty()) {
      front = rear = newNode;
    } else {
      rear.next = newNode;
      newNode.prev = rear;
      rear = newNode;
    }
  }

  public void deleteFront() {
    if (isEmpty()) {
      System.out.println("Deque is empty");
      return;
    }

    if (front == rear) {
      front = rear = null;
    } else {
      front = front.next;
      front.prev = null;
    }
  }

  public void deleteLast() {
    if (isEmpty()) {
      System.out.println("Deque is empty");
      return;
    }

    if (front == rear) {
      front = rear = null;
    } else {
      rear = rear.prev;
      rear.next = null;
    }
  }

  public int peekFront() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    return front.data;
  }

  public int peekRear() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    return rear.data;
  }

  public void display() {
    if (isEmpty()) {
      System.out.println("Deque is empty");
      return;
    }

    Node current = front;
    System.out.print("Deque: ");
    while (current != null) {
      System.out.print(current.data);
      if (current.next != null) {
        System.out.print(" <-> ");
      }
      current = current.next;
    }
    System.out.println();
  }

  public boolean isEmpty() {
    return front == null;
  }
}