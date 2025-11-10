//@ts-expect-error
import process from "node:process";
import { Node } from "../../node/Node";

class SinglyLinkedList {
	private head: Node | null;

	constructor(head: Node | null) {
		this.head = head;
	}

	public getHead(): Node | null {
		return this.head;
	}

	public getTail(): Node | null {
		if (this.head == null) return null;

		let n: Node | null | undefined = this.head;
		for (; n?.getNextNode() != null; n = n?.getNextNode());
		return n;
	}

	public popFront(): Node | null {
		if (this.head == null) return null;

		const n: Node | null = this.head;
		this.head = this.head.getNextNode();
		return n;
	}

	public popBack(): Node | null {
		if (this.head == null) return null;

		let n: Node | null | undefined = this.head;
		for (; n?.getNextNode()?.getNextNode() != null; n = n?.getNextNode());
		//@ts-expect-error
		const temp: Node = n.getNextNode();
		//@ts-expect-error
		n.setNextNode(null);
		return temp;
	}

	public pushFront(value: number): void {
		const n: Node = new Node(value, this.head);
		this.head = n;
	}

	public pushBack(value: number): void {
		const n: Node = new Node(value);
		let m: Node | null = this.head;
		for (; m?.getNextNode() != null; m = m?.getNextNode());
		m?.setNextNode(n);
	}

	public insert(value: number, position: number): void {
		const n: number = this.size();
		if (position >= n || position < 0) console.log("invalid postion");

		if (position === n - 1) this.pushBack(value);

		if (position === 0) this.pushFront(value);

		const nod: Node = new Node(value);
		let i: number = 0;
		let temp: Node | null = this.head;
		//@ts-expect-error
		for (; i !== position - 1 || temp != null; temp = temp.getNextNode(), i++);

		if (temp == null || temp === undefined) return;

		//@ts-expect-error
		temp.setNextNode(nod);
	}

	public search(key: number): boolean {
		if (this.head == null) return false;

		let n: Node | null = this.head;

		for (; n != null; n = n.getNextNode())
			if (n.getValue() === key) return true;

		return false;
	}

	public printList(): void {
		for (let n: Node | null = this.head; n != null; n = n.getNextNode());
		//@ts-expect-error
		process.std.write(`${n.getValue()} ->`);
		process.std.write("\n");
	}

	public size(): number {
		let i: number = 0;
		for (
			let node: Node | null = this.head;
			node != null;
			node = node.getNextNode(), i++
		);
		return i;
	}
}

export { SinglyLinkedList };
