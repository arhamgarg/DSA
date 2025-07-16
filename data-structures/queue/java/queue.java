public class queue {
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

    public void Enqueue(int data) {
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

    public int Dequeue() {
        if (head == null) {
            System.out.println("Queue is empty");
            return -1;
        }
        int value = head.data;
        size--;
        head = head.next;
        return value;
    }

    public int Front() {
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

    public static void main(String[] args) {

        queue q = new queue();

        q.Enqueue(1);
        q.Enqueue(64);
        q.Enqueue(23);
        q.Enqueue(6);

        System.out.println("Front: " + q.Front());
        System.out.println("Size: " + q.size());

        q.Dequeue();
        System.out.println("Front: " + q.Front());
        System.out.println("Size: " + q.size());

        System.out.println("Dequeue: " + q.Dequeue()); // 64
        System.out.println("Dequeue: " + q.Dequeue()); // 23
        System.out.println("Dequeue: " + q.Dequeue()); // 6
        System.out.println("Dequeue: " + q.Dequeue()); // Queue is empty → -1
    }


}
