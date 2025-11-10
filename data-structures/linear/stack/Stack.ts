//@ts-expect-error
import { process } from "node:process";
import type { Node } from "../node/Node";

class Stack {
	private head: Node | null;
	private size: number;

	constructor(head: Node | null = null) {
		this.head = head;
		this.size = 0;
	}

	public getHead(): Node | null {
		return this.head;
	}

	public getSize(): number {
		return this.size;
	}

	public push(node: Node): void {
		node.setNextNode(this.head);
		this.head = node;
	}

	public pop(): Node {
		if (this.head == null) {
			throw Error("Stack UnderFlow Exception");
		}

		const poppedNode: Node = this.head;
		this.head = this.head.getNextNode();
		return poppedNode;
	}

	public top(): Node {
		if (this.head == null) {
			throw Error("Stack UnderFlow Exception");
		}

		return this.head;
	}

	public display(): void {
		let n: Node | null = this.head;
		for (; n?.getNextNode() != null; n = n.getNextNode())
			process.std.write(`${n.getValue()} -> `);
		process.std.write();
	}
}

export { Stack };
