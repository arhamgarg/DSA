public class Node {
  int data;
  Node next;

  public Node(int data) {
    this.data = data;
    this.next = null;
  }
}

public class Stack {
  private Node head;
  private int size;

  public Stack() {
    head = null;
    size = 0;
  }

  public void push(int data) {
    Node newNode = new Node(data);
    newNode.next = head;
    head = newNode;
    size++;
  }

  public void pop() {
    if (head == null) {
      System.out.println("Stack is empty");
      return;
    }

    head = head.next;
    size--;
  }

  public int top() {
    if (head == null) {
      System.out.println("Stack is empty");
      return;
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
