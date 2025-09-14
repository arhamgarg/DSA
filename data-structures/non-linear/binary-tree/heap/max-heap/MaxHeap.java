import java.util.ArrayList;

public class MaxHeap {
    ArrayList<Integer> heap;

    public MaxHeap() {
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
        while (i > 0 && heap.get(i) > heap.get(parent(i))) {
            int temp = heap.get(i);
            heap.set(i, heap.get(parent(i)));
            heap.set(parent(i), temp);
            i = parent(i);
        }
    }

    void downHeap(int i) {
        int largest = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < heap.size() && heap.get(l) > heap.get(largest)) {
            largest = l;
        }
        if (r < heap.size() && heap.get(r) > heap.get(largest)) {
            largest = r;
        }
        if (largest != i) {
            int temp = heap.get(i);
            heap.set(i, heap.get(largest));
            heap.set(largest, temp);
            downHeap(largest);
        }
    }

    void insert(int key) {
        heap.add(key);
        upHeap(heap.size() - 1);
    }

    int getMax() {
        if (empty()) {
            System.out.println("Heap is empty!");
            return -1;
        }
        return heap.get(0);
    }

    int extractMax() {
        if (empty()) {
            System.out.println("Heap is empty!");
            return -1;
        }

        int root = heap.get(0);
        int last = heap.remove(heap.size() - 1);

        if (!empty()) {
            heap.set(0, last);
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
}