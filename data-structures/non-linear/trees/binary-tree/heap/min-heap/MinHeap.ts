class MinHeap {
	private heap: Array<number> = [];

	private getParent(index: number): number {
		return (index - 1) / 2;
	}

	private getLeftChild(index: number): number {
		return 2 * index + 1;
	}

	private getRightChild(index: number): number {
		return 2 * index + 2;
	}

	private upHeap(i: number): void {
		let temp: number;
		while (i > 0 && this.heap[i] < this.heap[this.getParent(i)]) {
			temp = this.heap[i];
			this.heap[i] = this.heap[this.getParent(i)];
			this.heap[this.getParent(i)] = temp;
			i = this.getParent(i);
		}
	}

	private downHeap(i: number): void {
		let smallest: number = i;
		const rightChild: number = this.getRightChild(i);
		const leftChild: number = this.getLeftChild(i);

		if (
			leftChild < this.heap.length &&
			this.heap[leftChild] < this.heap[smallest]
		) {
			smallest = leftChild;
		}

		if (
			rightChild < this.heap.length &&
			this.heap[rightChild] < this.heap[smallest]
		) {
			smallest = rightChild;
		}

		if (smallest !== i) {
			const temp: number = this.heap[smallest];
			this.heap[smallest] = this.heap[i];
			this.heap[i] = temp;
			this.downHeap(smallest);
		}
	}

	public insert(key: number): void {
		this.heap.push(key);
		this.upHeap(this.heap.length - 1);
	}

	public getMin(): number {
		if (this.isEmpty()) return -1;

		return this.heap[0];
	}

	public extractMin(): number {
		if (this.isEmpty()) return -1;

		const min: number = this.heap[0];

		//@ts-expect-error If the heap is empty the function terminates early, array.pop returns undefined when empty array
		this.heap[0] = this.heap.pop();

		//check if this.empty is required
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

	public isEmpty(): boolean {
		return this.heap.length === 0;
	}

	public size(): number {
		return this.heap.length;
	}
}

export { MinHeap };
