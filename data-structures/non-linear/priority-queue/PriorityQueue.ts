import { Heap } from "../trees/binary-tree/heap/Heap";

class PriorityQueue {
	private heap: Heap;

	constructor() {
		this.heap = new Heap();
	}

	public insertItem(key: number): void {
		this.heap.insert(key);
	}

	public removeTop(): number {
		if (this.heap.isEmpty()) {
			throw new Error("PriorityQueue is empty");
		}

		return this.heap.extractMin();
	}

	public topKey(): number {
		if (this.heap.isEmpty()) {
			throw new Error("PriorityQueue is empty");
		}

		return this.heap.getMin();
	}

	public buildHeap(heapArray: number[]): void {
		this.heap.buildHeap(heapArray);
	}

	public print(): void {
		this.heap.printHeap();
	}

	public empty(): boolean {
		return this.heap.isEmpty();
	}

	public size(): number {
		return this.heap.size();
	}
}

export { PriorityQueue };
