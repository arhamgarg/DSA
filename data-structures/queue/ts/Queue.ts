import { Node } from "../../node/ts/Node";
//@ts-ignore
import { process } from "node:process";

class Queue {
  private front: Node | null;

  constructor(front: Node | null = null) {
    this.front = front;
  }

  getFront(): Node | null {
    return this.front;
  }

  enqueue(node: Node): void {
    let n: Node | null = this.front;
    for (; n?.getNextNode() != null; n = n.getNextNode());
    node.setNextNode(null);
    n?.setNextNode(node);
  }

  dequeue(): Node | null {
    if (this.front == null) {
      return null;
    }
    //@ts-ignore
    let n: Node = this.front;
    this.front = this.front.getNextNode();
    return n;
  }

  size(): number {
    let i: number = 0;
    for (let n: Node | null = this.front; n != null; n = n.getNextNode(), i++);
    return i;
  }

  isEmpty(): boolean {
    return this.front == null;
  }

  display(): void {
    let n: Node | null = this.front;
    for (; n?.getNextNode() != null; n = n.getNextNode())
      //@ts-ignore
      process.std.write(`${n.getValue()} <- `);
    //@ts-ignore
    process.std.write();
  }
}

export { Queue };
