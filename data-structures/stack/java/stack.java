public class stack{
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

    public void Push(int data) {
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

    public int Pop(){
        if(head == null){
            System.out.println("Stack is empty");
        }

        int value = head.data;
        head = head.next;
        size--;

        return value;
    }

    public int size() {
        return size;
    }

    public int top(){
        return head.data;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public static void main(String[] args) {
        stack Stack = new stack();

        Stack.Push(23);
        Stack.Push(6);
        Stack.Push(69);
        Stack.Push(64);
        Stack.Push(1);
        Stack.Push(4);
        Stack.Push(47);

        System.out.println("Top : "+Stack.top());

        System.out.println("Pop : " + Stack.Pop());
        System.out.println("Pop : "+Stack.Pop());

        System.out.println("Size : "+Stack.size());
        System.out.println("Empty or Not : "+Stack.isEmpty());


    }
}