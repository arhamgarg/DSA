public class linked_list {
    Node head;
    private int size;

    class Node{
        int data;
        Node next;

        Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public void AddFront(int data){
        Node newNode = new Node(data);

        if(head == null){
            head = newNode;
            size ++;
            return;
        }

        newNode.next = head;
        head = newNode;
        size++;
    }

    public void AddLast(int data){
        Node newNode = new Node(data);

        if (head == null) {
            head = newNode;
            return;
        }

        Node currNode = head;
        while (currNode.next != null) {
            currNode = currNode.next;
        }

        currNode.next = newNode;
        size++;
    }

    public boolean Search(int value){
        Node currNode = head;

        while(currNode != null){
            if(currNode.data == value){
                return true;
            }
            currNode = currNode.next;
        }
        return false;
    }

    public void PrintList() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }

        Node currNode = head;

        while (currNode != null) {
            System.out.print(currNode.data + "-->");
            currNode = currNode.next;
        }

        System.out.println("NULL");

    }

    public void DeleteFirst() {
        if (head == null) {
            System.out.println("List is empty");
            return;
        }
        size--;
        head = head.next;
    }

    public void DeleteLast(){
        if (head == null) {
            System.out.println("Lsit is empty");
            return;
        }

        if (head.next == null) {
            head = null;
            return;
        }

        Node secondLast = head;
        Node lastNode = head.next;

        while (lastNode.next != null) {
            lastNode = lastNode.next;
            secondLast = secondLast.next;
        }

        size--;
        secondLast.next = null;

    }

    public int size() {
        return size;
    }


    public static void main(String[] args) {
        linked_list ll = new linked_list();

        ll.AddFront(6);
        ll.AddLast(23);
        ll.AddLast(64);
        ll.AddFront(1);
        ll.AddLast(4);
        ll.AddFront(47);
        ll.AddLast(69);

        ll.PrintList();
        System.out.println("Size: " + ll.size());

        ll.DeleteFirst();
        System.out.println("Deleted First");
        ll.PrintList();

        ll.DeleteLast();
        System.out.println("Deleted Last");
        ll.PrintList();

        System.out.println("Search 23: " + ll.Search(23));
        System.out.println("Search 99: " + ll.Search(99));


    }

}
