//@ts-expect-error
import { process } from "node:process";
import type { Node } from "../node/Node";

class Queue {
	private front: Node | null;

	constructor(front: Node | null = null) {
		this.front = front;
	}

	public getFront(): Node | null {
		return this.front;
	}

	public enqueue(node: Node): void {
		let n: Node | null = this.front;
		for (; n?.getNextNode() != null; n = n.getNextNode());
		node.setNextNode(null);
		n?.setNextNode(node);
	}

	public dequeue(): Node | null {
		if (this.front == null) {
			return null;
		}
		const n: Node = this.front;
		this.front = this.front.getNextNode();
		return n;
	}

	public size(): number {
		let i: number = 0;
		for (let n: Node | null = this.front; n != null; n = n.getNextNode(), i++);
		return i;
	}

	public isEmpty(): boolean {
		return this.front == null;
	}

	public display(): void {
		let n: Node | null = this.front;
		for (; n?.getNextNode() != null; n = n.getNextNode())
			process.std.write(`${n.getValue()} <- `);
		process.std.write();
	}
}

export { Queue };
