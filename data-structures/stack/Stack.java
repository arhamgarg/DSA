public class Stack {
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

  public void push(int data) {
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

  public int pop() {
    if (head == null) {
      System.out.println("Stack is empty");
    }

    int value = head.data;
    head = head.next;
    size--;

    return value;
  }

  public int top() {
    return head.data;
  }

  public int size() {
    return size;
  }

  public boolean isEmpty() {
    return size == 0;
  }
}
