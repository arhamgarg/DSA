class Node {
  int data;
  Node prev, next;

  public Node(int data) {
    this.data = data;
    this.prev = null;
    this.next = null;
  }
}

public class Deque {
  private Node front, rear;
  private int size;

  public Deque() {
    front = rear = null;
    size = 0;
  }

  public boolean isEmpty() {
    return size == 0;
  }

  public void insertFront(int data) {
    Node newNode = new Node(data);
    if (isEmpty()) {
      front = rear = newNode;
    } else {
      newNode.next = front;
      front.prev = newNode;
      front = newNode;
    }
    size++;
  }

  public void insertRear(int data) {
    Node newNode = new Node(data);
    if (isEmpty()) {
      front = rear = newNode;
    } else {
      newNode.prev = rear;
      rear.next = newNode;
      rear = newNode;
    }
    size++;
  }

  public int deleteFront() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    int value = front.data;
    front = front.next;
    if (front == null) {
      rear = null;
    } else {
      front.prev = null;
    }
    size--;
    return value;
  }

  public int deleteRear() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    int value = rear.data;
    rear = rear.prev;
    if (rear == null) {
      front = null;
    } else {
      rear.next = null;
    }
    size--;
    return value;
  }

  public int getFront() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    return front.data;
  }

  public int getRear() {
    if (isEmpty()) {
      throw new RuntimeException("Deque is empty");
    }
    return rear.data;
  }

  public int size() {
    return size;
  }
}
