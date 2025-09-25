import { MaxHeap } from "../binary-tree/heap/max-heap/MaxHeap";
import { MinHeap } from "../binary-tree/heap/min-heap/MinHeap";

class PriorityQueue {
  private isMinQueue: boolean;
  private minHeap: MinHeap;
  private maxHeap: MaxHeap;

  constructor(type: boolean = true) {
    this.isMinQueue = type;
  }

  //Naming issues
  public isMinimumQueue(): boolean {
    return this.isMinQueue;
  }

  public insertItem(key: number): void {
    if (this.isMinQueue) {
      this.minHeap.insert(key);
      return;
    }

    this.maxHeap.insert(key);
  }

  public removeTop(): number {
    if (this.isMinQueue) {
      return this.minHeap.extractMin();
    }

    return this.maxHeap.extractMax();
  }

  public topKey(): number {
    if (this.isMinQueue) {
      return this.minHeap.getMin();
    }

    return this.maxHeap.getMax();
  }

  public buildHeap(heapArray: Array<number>): void {
    if (this.isMinQueue) {
      this.minHeap.buildHeap(heapArray);
      return;
    }

    this.maxHeap.buildHeap(heapArray);
  }

  public printHeap(): void {
    if (this.isMinQueue) {
      this.minHeap.printHeap();
      return;
    }

    this.maxHeap.printHeap();
  }

  public isEmpty(): boolean {
    if (this.isMinQueue) {
      return this.minHeap.isEmpty();
    }

    return this.maxHeap.isEmpty();
  }

  public size(): number {
    if (this.isMinQueue) {
      return this.minHeap.size();
    }

    return this.maxHeap.size();
  }
}

export { PriorityQueue };
