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

  // Add element to front
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

  // Add element to rear
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

  // Remove from front
  public void deleteFront() {
    if (isEmpty()) {
      System.out.println("Deqeu is empty");
      return;
    }

    if (front == rear) {
      front = rear = null;
    } else {
      front = front.next;
      front.prev = null;
    }
  }

  // Remove from rear
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

  // Peek front
  public int peekFront() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    return front.data;
  }

  // Peek rear
  public int peekRear() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    return rear.data;
  }

  // Check if empty
  public boolean isEmpty() {
    return front == null;
  }
}
