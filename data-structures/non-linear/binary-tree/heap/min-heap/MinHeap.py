class MinHeap:
    def __init__(self, arr=None):
        self.heap = []
        if arr:
            self.build_heap(arr)

    def _left(self, i): return 2 * i + 1
    def _right(self, i): return 2 * i + 2
    def _parent(self, i): return (i - 1) // 2

    def _heapify(self, i):
        """Fix the heap property going downwards"""
        n = len(self.heap)
        smallest = i
        l, r = self._left(i), self._right(i)

        if l < n and self.heap[l] < self.heap[smallest]:
            smallest = l
        if r < n and self.heap[r] < self.heap[smallest]:
            smallest = r

        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self._heapify(smallest)

    def build_heap(self, arr):
        """Build heap in O(n) using bottom-up heapify"""
        self.heap = arr[:]  
        n = len(self.heap)
        for i in range(n // 2 - 1, -1, -1):
            self._heapify(i)

    def extract_min(self):
        if not self.heap:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()

        root = self.heap[0]
        self.heap[0] = self.heap.pop()  # move last to root
        self._heapify(0)
        return root

    def insert(self, key):
        """Insert in O(log n)"""
        self.heap.append(key)
        i = len(self.heap) - 1
        while i > 0 and self.heap[self._parent(i)] > self.heap[i]:
            self.heap[self._parent(i)], self.heap[i] = self.heap[i], self.heap[self._parent(i)]
            i = self._parent(i)

    def get_min(self):
        return None if not self.heap else self.heap[0]

    def size(self):
        return len(self.heap)

    def display(self):
        print(self.heap)
