class Node {
  private value: number;
  private nextNode: Node | null;

  constructor(value: number, nextNode: Node | null = null) {
    this.value = value;
    this.nextNode = nextNode;
  }

  getValue(): number {
    return this.value;
  }

  getNextNode(): Node | null {
    return this.nextNode;
  }

  setNextNode(nextNode: Node | null): void {
    this.nextNode = nextNode;
  }
}

export { Node };
