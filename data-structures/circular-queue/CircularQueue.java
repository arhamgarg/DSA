
public class CircularQueue {
  private int[] arr;
  private int maxSize, currSize;
  private int f, b;

  public CircularQueue(int size) {
    maxSize = size;
    arr = new int[maxSize];
    currSize = 0;
    f = 0;
    b = -1;
  }

  public void enqueue(int value) {
    if (currSize == maxSize) {
      System.out.println("circular queue is full!");
      return;
    }
    b = (b + 1) % maxSize;
    arr[b] = value;
    currSize++;
  }

  public void dequeue() {
    if (isEmpty()) {
      System.out.println("circular queue is empty!");
      return;
    }
    f = (f + 1) % maxSize;
    currSize--;
  }

  public int front() {
    if (isEmpty()) {
      System.out.println("circular queue is empty!");
      return -1;
    }
    return arr[f];
  }


  public int last() {
    if (isEmpty()) {
      System.out.println("circular queue is empty!");
      return -1;
    }
    return arr[b];
  }

  public boolean isFull() {
    return currSize == maxSize;
  }

  public boolean isEmpty() {
    return currSize == 0;
  }

  public int size() {
    return currSize;
  }
}
