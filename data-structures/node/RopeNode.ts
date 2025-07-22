class RopeNode {
  private value: number;
  private nextNode: RopeNode | null;
  private previousNode: RopeNode | null;

  constructor(
    value: number,
    nextNode: RopeNode | null = null,
    previousNode: RopeNode | null = null,
  ) {
    this.value = value;
    this.nextNode = nextNode;
    this.previousNode = previousNode;
  }

  getValue(): number {
    return this.value;
  }

  getNextNode(): RopeNode | null {
    return this.nextNode;
  }

  getPreviousNode(): RopeNode | null {
    return this.previousNode;
  }

  setNextNode(node: RopeNode | null): void {
    this.nextNode = node;
  }

  setPreviousNode(node: RopeNode | null): void {
    this.previousNode = node;
  }
}

export { RopeNode };
