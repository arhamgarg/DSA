class Node {
  private value: number;
  private nextNode: Node | null;

  constructor(value: number, nextNode: Node | null = null) {
    this.value = value;
    this.nextNode = nextNode;
  }

  public getValue(): number {
    return this.value;
  }

  public getNextNode(): Node | null {
    return this.nextNode;
  }

  public setNextNode(nextNode: Node | null): void {
    this.nextNode = nextNode;
  }
}

export { Node };
