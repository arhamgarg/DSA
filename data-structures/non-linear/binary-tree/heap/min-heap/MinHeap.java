import java.util.ArrayList;

class MinHeap {
    ArrayList<Integer> heap;

    public MinHeap() {
        heap = new ArrayList<>();
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return 2 * i + 1;
    }

    int rightChild(int i) {
        return 2 * i + 2;
    }

    void upHeap(int i) {
        while (i > 0 && heap.get(i) < heap.get(parent(i))) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    void downHeap(int i) {
        int smallest = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heap.size() && heap.get(l) < heap.get(smallest)) {
            smallest = l;
        }

        if (r < heap.size() && heap.get(r) < heap.get(smallest)) {
            smallest = r;
        }

        if (smallest != i) {
            swap(i, smallest);
            downHeap(smallest);
        }
    }

    void insert(int key) {
        heap.add(key);
        upHeap(heap.size() - 1);
    }

    int getMin() {
        if (empty()) {
            System.out.println("Heap is empty!");
            return -1;
        }
        return heap.get(0);
    }

    int extractMin() {
        if (empty()) {
            System.out.println("Heap is empty!");
            return -1;
        }

        int root = heap.get(0);

        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);

        if (!empty()) {
            downHeap(0);
        }

        return root;
    }

    void buildHeap(ArrayList<Integer> arr) {
        heap = new ArrayList<>(arr);
        for (int i = parent(heap.size() - 1); i >= 0; i--) {
            downHeap(i);
        }
    }

    void printHeap() {
        for (int x : heap) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    boolean empty() {
        return heap.isEmpty();
    }

    int size() {
        return heap.size();
    }

    void swap(int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }
}