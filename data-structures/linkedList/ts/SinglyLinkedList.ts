import { Node } from "../../node/ts/Node";
//@ts-ignore
import process from "node:process";

class SinglyLinkedList {
  private head: Node | null;

  constructor(head: Node | null) {
    this.head = head;
  }

  getHead(): Node | null {
    return this.head;
  }

  getTail(): Node | null {
    if (this.head == null) return null;

    let n: Node | null | undefined = this.head;
    for (; n?.getNextNode() != null; n = n?.getNextNode());
    return n;
  }

  popFront(): Node | null {
    if (this.head == null) return null;

    let n: Node | null = this.head;
    this.head = this.head.getNextNode();
    return n;
  }

  popBack(): Node | null {
    if (this.head == null) return null;

    let n: Node | null | undefined = this.head;
    for (; n?.getNextNode()?.getNextNode() != null; n = n?.getNextNode());
    //@ts-ignore
    let temp: Node = n.getNextNode();
    //@ts-ignore
    n.setNextNode(null);
    return temp;
  }

  pushFront(value: number): void {
    let n: Node = new Node(value, this.head);
    this.head = n;
  }

  pushBack(value: number): void {
    let n: Node = new Node(value);
    let m: Node | null = this.head;
    for (; m?.getNextNode() != null; m = m?.getNextNode());
    m?.setNextNode(n);
  }

  insert(value: number, position: number): void {
    let n: number = this.size();
    if (position >= n || position < 0) return console.log("invalid postion");

    if (position == n - 1) return this.pushBack(value);

    if (position == 0) return this.pushFront(value);

    let nod: Node = new Node(value);
    let i: number = 0;
    let temp: Node | null = this.head;
    //@ts-ignore
    for (; i != position - 1 || temp != null; temp = temp.getNextNode(), i++);

    if (temp == null || temp == undefined) return;

    //@ts-ignore
    temp.setNextNode(nod);
  }

  search(key: number): boolean {
    if (this.head == null) return false;

    let n: Node | null = this.head;

    for (; n != null; n = n.getNextNode()) if (n.getValue() == key) return true;

    return false;
  }

  printList(): void {
    for (let n: Node | null = this.head; n != null; n = n.getNextNode());
    //@ts-ignore
    process.std.write(`${n.getValue()} ->`);
    //@ts-ignore
    process.std.write("\n");
  }

  size(): number {
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
