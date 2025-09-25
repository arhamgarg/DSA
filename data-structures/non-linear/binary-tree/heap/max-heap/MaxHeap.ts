class MaxHeap {
  private heap: Array<number>;

  private getParent(index: number): number {
    return (index - 1) / 2;
  }

  private getLeftChild(index: number): number {
    return index * 2 + 1;
  }

  private getRightChild(index: number): number {
    return index * 2 + 2;
  }

  private upHeap(index: number): void {
    let temp: number;
    while (index > 0 && this.heap[index] > this.heap[this.getParent(index)]) {
      temp = this.heap[index];
      this.heap[index] = this.heap[this.getParent(index)];
      this.heap[this.getParent(index)] = temp;
      index = this.getParent(index);
    }
  }

  private downHeap(index: number): void {
    let smallest: number = index;
    const leftChild: number = this.getLeftChild(index);
    const rightChild: number = this.getRightChild(index);

    if (
      leftChild < this.heap.length &&
      this.heap[smallest] < this.heap[leftChild]
    ) {
      smallest = leftChild;
    }

    if (
      rightChild < this.heap.length &&
      this.heap[smallest] < this.heap[rightChild]
    ) {
      smallest = leftChild;
    }

    if (index != smallest) {
      const temp: number = this.heap[index];
      this.heap[index] = this.heap[smallest];
      this.heap[smallest] = temp;
      this.upHeap(smallest);
    }
  }

  public isEmpty(): boolean {
    return this.heap.length == 0;
  }

  public size(): number {
    return this.heap.length;
  }

  public insert(key: number): void {
    this.heap.push(key);
    this.upHeap(this.heap.length - 1);
  }

  public getMax(): number {
    if (this.isEmpty()) return -1;

    return this.heap[0];
  }

  public extractMax(): number {
    if (this.isEmpty()) return -1;

    const min: number = this.heap[0];

    //@ts-expect-error If the heap is empty the function terminates early, array.pop returns undefined when empty array
    this.heap[0] = this.heap.pop();

    if (!this.isEmpty()) {
      this.downHeap(0);
    }

    return min;
  }

  public buildHeap(heapArray: Array<number>): void {
    this.heap = heapArray;

    for (let i = this.getParent(this.heap.length - 1); i >= 0; i--) {
      this.downHeap(i);
    }
  }

  public printHeap(): void {
    for (const x of this.heap) {
      console.log(`${x}`);
    }
  }
}

export { MaxHeap };
