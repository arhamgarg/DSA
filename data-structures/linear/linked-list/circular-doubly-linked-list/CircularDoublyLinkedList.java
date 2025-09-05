class Node {
  int data;
  Node next;
  Node prev;

  Node(int value) {
    this.data = value;
    this.next = this.prev = null;
  }
}

class DoublyCircularLinkedList {
  private Node head;
  private Node tail;

  DoublyCircularLinkedList() {
    this.head = null;
    this.tail = null;
  }

  // ------------- Core Operations -------------

  boolean isEmpty() {
    return head == null;
  }

  void TraverseForward() {
    if (head == null) {
      System.out.println("Empty");
      return;
    }
    Node temp = head;
    do {
      System.out.print(temp.data + " <-> ");
      temp = temp.next;
    } while (temp != head);
    System.out.println("(back to head)");
  }

  void TraverseBackward() {
    if (head == null) {
      System.out.println("Empty");
      return;
    }
    Node temp = tail;
    do {
      System.out.print(temp.data + " <-> ");
      temp = temp.prev;
    } while (temp != tail);
    System.out.println("(back to tail)");
  }

  void Search(int searchData) {
    if (head == null) {
      System.out.println("Empty");
      return;
    }
    int pos = 0;
    Node temp = head;
    do {
      if (temp.data == searchData) {
        System.out.println("Data " + temp.data + " found at position " + pos);
        return;
      }
      pos++;
      temp = temp.next;
    } while (temp != head);
    System.out.println("Data " + searchData + " not found");
  }

  int front() {
    if (head == null) {
      System.out.println("List empty");
      return -1;
    }
    return head.data;
  }

  int back() {
    if (tail == null) {
      System.out.println("List empty");
      return -1;
    }
    return tail.data;
  }

  int size() {
    if (head == null)
      return 0;
    int count = 0;
    Node temp = head;
    do {
      count++;
      temp = temp.next;
    } while (temp != head);
    return count;
  }

  // ------------- Insertions -------------

  void insertFirst(int value) {
    Node newNode = new Node(value);
    if (head == null) {
      head = tail = newNode;
      newNode.next = newNode.prev = newNode;
    } else {
      newNode.next = head;
      newNode.prev = tail;
      tail.next = newNode;
      head.prev = newNode;
      head = newNode;
    }
  }

  void insertLast(int value) {
    Node newNode = new Node(value);
    if (head == null) {
      head = tail = newNode;
      newNode.next = newNode.prev = newNode;
    } else {
      newNode.prev = tail;
      newNode.next = head;
      tail.next = newNode;
      head.prev = newNode;
      tail = newNode;
    }
  }

  void insertAt(int position, int value) {
    if (position == 0) {
      insertFirst(value);
      return;
    }

    Node temp = head;
    int count = 0;
    while (count < position - 1 && temp.next != head) {
      temp = temp.next;
      count++;
    }

    if (count != position - 1) {
      System.out.println("Position out of range");
      return;
    }

    Node newNode = new Node(value);
    newNode.next = temp.next;
    newNode.prev = temp;
    temp.next.prev = newNode;
    temp.next = newNode;

    if (temp == tail) {
      tail = newNode;
    }
  }

  // ------------- Deletions -------------

  void deleteFirst() {
    if (head == null)
      return;

    if (head == tail) {
      System.out.println("Deleted value : " + head.data);
      head = tail = null;
      return;
    }
    System.out.println("Deleted value : " + head.data);
    head = head.next;
    head.prev = tail;
    tail.next = head;
  }

  void deleteLast() {
    if (head == null)
      return;

    if (head == tail) {
      System.out.println("Deleted value : " + head.data);
      head = tail = null;
      return;
    }
    System.out.println("Deleted value : " + tail.data);
    tail = tail.prev;
    tail.next = head;
    head.prev = tail;
  }

  void deleteAt(int position) {
    if (head == null)
      return;
    if (position == 0) {
      deleteFirst();
      return;
    }

    Node temp = head;
    int count = 0;
    while (count < position - 1 && temp.next != head) {
      temp = temp.next;
      count++;
    }

    if (count != position - 1 || temp.next == head) {
      System.out.println("Position out of range");
      return;
    }

    Node toDelete = temp.next;
    System.out.println("Deleted: " + toDelete.data);
    temp.next = toDelete.next;
    toDelete.next.prev = temp;

    if (toDelete == tail) {
      tail = temp;
    }
  }

  void deleteKey(int deleteData) {
    if (head == null)
      return;

    Node temp = head;
    do {
      if (temp.data == deleteData) {
        if (temp == head && temp == tail) {
          System.out.println("Deleted value: " + temp.data);
          head = tail = null;
          return;
        } else if (temp == head) {
          deleteFirst();
          return;
        } else if (temp == tail) {
          deleteLast();
          return;
        } else {
          temp.prev.next = temp.next;
          temp.next.prev = temp.prev;
          System.out.println("Deleted value: " + temp.data);
          return;
        }
      }
      temp = temp.next;
    } while (temp != head);

    System.out.println("Node with given data: " + deleteData + " not found");
  }

  // ------------- Utilities -------------
  // 😎💀📔
  void update(int updateVal, int newData) {
    if (head == null) {
      System.out.println("Empty List");
      return;
    }
    Node temp = head;
    do {
      if (temp.data == updateVal) {
        temp.data = newData;
        System.out.println("Node updated: " + updateVal + " -> " + newData);
        return;
      }
      temp = temp.next;
    } while (temp != head);
    System.out.println("Node with given data: " + updateVal + " not found");
  }

  void reverse() {
    if (head == null) {
      System.out.println("Empty List");
      return;
    }
    Node current = head, temp = null;
    do {
      temp = current.prev;
      current.prev = current.next;
      current.next = temp;
      current = current.prev;
    } while (current != head);

    temp = head;
    head = tail;
    tail = temp;
  }
}

public class CircularDoublyLinkedList {
  public static void main(String[] args) {
    DoublyCircularLinkedList list = new DoublyCircularLinkedList();

    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.TraverseForward();

    list.insertFirst(5);
    list.TraverseForward();

    list.insertAt(2, 15);
    list.TraverseForward();

    System.out.println("Front: " + list.front());
    System.out.println("Back: " + list.back());
    System.out.println("Size: " + list.size());

    list.deleteFirst();
    list.TraverseForward();

    list.deleteLast();
    list.TraverseForward();

    list.deleteAt(1);
    list.TraverseForward();

    list.deleteKey(15);
    list.TraverseForward();

    list.update(20, 200);
    list.TraverseForward();

    list.reverse();
    list.TraverseForward();
    list.TraverseBackward();
  }
}
