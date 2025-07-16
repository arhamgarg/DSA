import { Node } from "../../node/ts/Node";
//@ts-ignore
import { process } from "node:process";

class Stack {
  private head: Node | null;
  private size: number;

  constructor(head: Node | null = null) {
    this.head = head;
    this.size = 0;
  }

  getHead(): Node | null {
    return this.head;
  }

  getSize(): number {
    return this.size;
  }

  push(node: Node): void {
    node.setNextNode(this.head);
    this.head = node;
  }

  pop(): Node {
    if (this.head == null) {
      throw Error("Stack UnderFlow Exception");
    }

    let poppedNode: Node = this.head;
    this.head = this.head.getNextNode();
    return poppedNode;
  }

  top(): Node {
    if (this.head == null) {
      throw Error("Stack UnderFlow Exception");
    }

    return this.head;
  }

  display(): void {
    let n: Node | null = this.head;
    for (; n?.getNextNode() != null; n = n.getNextNode())
      //@ts-ignore
      process.std.write(`${n.getValue()} -> `);
    //@ts-ignore
    process.std.write();
  }
}

export { Stack };
