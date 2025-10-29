# Uses MinHeap ADT from data-structures/non-linear/binary-tree/heap/min-heap/MinHeap.py


class Graph:
    class Node:
        def __init__(self, e):
            self.AList = []  # neighbors (neighbor_value, weight)
            self.value = e

        def addtoAList(self, neighbor, w):
            self.AList.append((neighbor, w))

    class Edge:
        def __init__(self, v1, v2, w):
            self.v1 = v1
            self.v2 = v2
            self.weight = w

    def __init__(self):
        self.nodes = {}  # key: node value, value: Node
        self.edges = []  # list of edges (weight, v1, v2)
        self.vertices = set()

    def insertNode(self, e):
        if e not in self.nodes:
            self.nodes[e] = self.Node(e)
            self.vertices.add(e)

    def insertEdge(self, v1, v2, w):
        if v1 not in self.nodes or v2 not in self.nodes:
            print("Vertex not found")
            return
        for n, weight in self.nodes[v1].AList:
            if n == v2:
                print(f"Edge {v1}-{v2} already exists")
                return
        self.nodes[v1].addtoAList(v2, w)
        self.nodes[v2].addtoAList(v1, w)

        edge = self.Edge(v1, v2, w)
        self.edges.append(edge)

    def getNode(self, e):
        return self.nodes.get(e, None)

    def DFS(self, v, visited=None):
        if v is None:
            return
        if visited is None:
            visited = set()
        visited.add(v.value)
        print(v.value, end=" ")
        for neighbor, _ in v.AList:
            if neighbor not in visited:
                self.DFS(self.nodes[neighbor], visited)

    def BFS(self, v):
        if v is None:
            return
        visited = set()
        q = [v]
        visited.add(v.value)
        while q:
            node = q.pop(0)
            print(node.value, end=" ")
            for neighbor, _ in node.AList:
                if neighbor not in visited:
                    visited.add(neighbor)
                    q.append(self.nodes[neighbor])

    def MST_Prim(self, start):
        if start not in self.nodes:
            print("Invalid start vertex")
            return
        visited = set([start])
        heap = MinHeap()
        mst, total_weight = [], 0
        for neighbor, w in self.nodes[start].AList:
            heap.insert((w, start, neighbor))
        while heap.size() > 0 and len(visited) < len(self.vertices):
            w, u, v = heap.extract_min()
            if v not in visited:
                visited.add(v)
                mst.append((u, v, w))
                total_weight += w
                for n, wt in self.nodes[v].AList:
                    if n not in visited:
                        heap.insert((wt, v, n))
        print("\nMST (Prim's):")
        for u, v, w in mst:
            print(f"{u} -- {v}  weight = {w}")
        print("Total Weight:", total_weight, "\n")

    def MST_Kruskal(self):
        parent = {}
        rank = {}

        def find(v):
            if parent[v] != v:
                parent[v] = find(parent[v])
            return parent[v]

        def union(u, v):
            root1 = find(u)
            root2 = find(v)
            if root1 != root2:
                if rank[root1] < rank[root2]:
                    parent[root1] = root2
                elif rank[root1] > rank[root2]:
                    parent[root2] = root1
                else:
                    parent[root2] = root1
                    rank[root1] += 1

        for node in self.nodes:
            parent[node] = node
            rank[node] = 0

        heap = MinHeap([(edge.weight, edge.v1, edge.v2) for edge in self.edges])
        sorted_edges = [heap.extract_min() for _ in range(len(self.edges))]

        MST = []
        total_weight = 0

        for w, u, v in sorted_edges:
            if find(u) != find(v):
                union(u, v)
                MST.append((u, v, w))
                total_weight += w

        print("\nKruskal's MST:")
        for u, v, w in MST:
            print(f"{u} - {v} : {w}")
        print("Total Weight:", total_weight)

    def ShortestPath(self, start):
        if start not in self.nodes:
            print("Invalid start vertex")
            return
        distances = {v: float("inf") for v in self.vertices}
        parent = {v: None for v in self.vertices}
        distances[start] = 0
        visited = set()
        heap = MinHeap([(0, start)])
        while heap.size() > 0:
            dist, u = heap.extract_min()
            if u in visited:
                continue
            visited.add(u)
            for neighbor, w in self.nodes[u].AList:
                new_dist = dist + w
                if new_dist < distances[neighbor]:
                    distances[neighbor] = new_dist
                    parent[neighbor] = u
                    heap.insert((new_dist, neighbor))
        print(f"\nShortest paths from {start}:")
        for v in self.vertices:
            if distances[v] == float("inf"):
                print(f"{start} → {v}: No path")
            else:
                path = []
                node = v
                while node is not None:
                    path.insert(0, node)
                    node = parent[node]
                print(
                    f"{start} → {v}: Distance = {distances[v]}, Path = {' -> '.join(path)}"
                )

    def printGraph(self):
        print("\nGraph Adjacency List:")
        for key, node in self.nodes.items():
            print(f"{key}: {node.AList}")
        print("")


def main():
    graph = Graph()
    inputs = int(input())
    while inputs > 0:
        command = input()
        operation = command.split()
        if operation[0] == "IN":
            graph.insertNode(operation[1])
        elif operation[0] == "IE":
            graph.insertEdge(operation[1], operation[2], int(operation[3]))
            graph.printGraph()
        elif operation[0] == "DFS":
            graph.DFS(graph.getNode(operation[1]))
            print("")
        elif operation[0] == "BFS":
            graph.BFS(graph.getNode(operation[1]))
            print("")
        elif operation[0] == "PRIM":
            graph.MST_Prim(operation[1])
        elif operation[0] == "KRUSKAL":
            graph.MST_Kruskal()
        elif operation[0] == "DIJKSTRA":
            graph.ShortestPath(operation[1])
        inputs -= 1


if __name__ == "__main__":
    main()
