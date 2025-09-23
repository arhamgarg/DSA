class GraphNode {
  private neighbouringNodes: Array<GraphNode>;
  private value: number;

  constructor(value: number) {
    this.neighbouringNodes = new Array();
    this.value = value;
  }

  public addNewNeighouringNode(node: GraphNode): void {
    this.neighbouringNodes.push(node);
  }

  public getValue(): number {
    return this.value;
  }
}

class Graph {
  private nodes: Array<GraphNode>;

  constructor() {
    this.nodes = new Array();
  }

  public addNewNode(value: number): GraphNode {
    const newGraphNode: GraphNode = new GraphNode(value);
    this.nodes.push(newGraphNode);
    return newGraphNode;
  }

  public addNewEdge(source: GraphNode, destination: GraphNode): void {
    source.addNewNeighouringNode(destination);
  }
}
