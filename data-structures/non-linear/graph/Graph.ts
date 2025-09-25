class GraphVertex {
  private neighbouringVertices: Array<GraphVertex>;
  private value: number;

  constructor(value: number) {
    this.neighbouringVertices = new Array();
    this.value = value;
  }

  public addNewNeighouringVertex(Vertex: GraphVertex): void {
    this.neighbouringVertices.push(Vertex);
  }

  public getValue(): number {
    return this.value;
  }
}

class Graph {
  private Vertices: Array<GraphVertex>;

  constructor() {
    this.Vertices = new Array();
  }

  public addNewVertex(value: number): GraphVertex {
    const newGraphVertex: GraphVertex = new GraphVertex(value);
    this.Vertices.push(newGraphVertex);
    return newGraphVertex;
  }

  public addNewEdge(source: GraphVertex, destination: GraphVertex): void {
    source.addNewNeighouringVertex(destination);
  }
}
