class MinHeap:
    def __init__(self, arr=None):
        self.heap = []
        if arr:
            self.build_heap(arr)

    def _left(self, i):
        return 2 * i + 1

    def _right(self, i):
        return 2 * i + 2

    def _parent(self, i):
        return (i - 1) // 2

    def _heapify(self, i):
        n = len(self.heap)
        smallest = i
        l, r = self._left(i), self._right(i)
        if l < n and self.heap[l] < self.heap[smallest]:
            smallest = l
        if r < n and self.heap[r] < self.heap[smallest]:
            smallest = r
        if smallest != i:
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self._heapify(smallest)

    def build_heap(self, arr):
        self.heap = arr[:]
        for i in range(len(self.heap) // 2 - 1, -1, -1):
            self._heapify(i)

    def extract_min(self):
        if not self.heap:
            return None
        if len(self.heap) == 1:
            return self.heap.pop()
        root = self.heap[0]
        self.heap[0] = self.heap.pop()
        self._heapify(0)
        return root

    def insert(self, key):
        self.heap.append(key)
        i = len(self.heap) - 1
        while i > 0 and self.heap[self._parent(i)] > self.heap[i]:
            self.heap[i], self.heap[self._parent(i)] = (
                self.heap[self._parent(i)],
                self.heap[i],
            )
            i = self._parent(i)

    def size(self):
        return len(self.heap)


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
        self.edges.append((w, v1, v2))

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
        parent = {v: v for v in self.vertices}
        rank = {v: 0 for v in self.vertices}
        mst = []

        def find(v):
            if parent[v] != v:
                parent[v] = find(parent[v])
            return parent[v]

        def union(u, v):
            ru, rv = find(u), find(v)
            if ru != rv:
                if rank[ru] < rank[rv]:
                    parent[ru] = rv
                elif rank[ru] > rank[rv]:
                    parent[rv] = ru
                else:
                    parent[rv] = ru
                    rank[ru] += 1
                return True
            return False

        heap = MinHeap(self.edges)
        sorted_edges = [heap.extract_min() for _ in range(len(self.edges))]
        for w, u, v in sorted_edges:
            if union(u, v):
                mst.append((u, v, w))
                if len(mst) == len(self.vertices) - 1:
                    break
        total_weight = sum(w for _, _, w in mst)
        print("\nMST (Kruskal's):")
        for u, v, w in mst:
            print(f"{u} -- {v}  weight = {w}")
        print("Total Weight:", total_weight, "\n")

    def MST_Boruvka(self):
        parent = {v: v for v in self.vertices}
        rank = {v: 0 for v in self.vertices}
        mst, total_weight = [], 0
        num_components = len(self.vertices)

        def find(v):
            while parent[v] != v:
                parent[v] = parent[parent[v]]
                v = parent[v]
            return v

        def union(u, v):
            ru, rv = find(u), find(v)
            if ru != rv:
                if rank[ru] < rank[rv]:
                    parent[ru] = rv
                elif rank[ru] > rank[rv]:
                    parent[rv] = ru
                else:
                    parent[rv] = ru
                    rank[ru] += 1
                return True
            return False

        while num_components > 1:
            cheapest = {}
            for w, u, v in self.edges:
                set_u, set_v = find(u), find(v)
                if set_u != set_v:
                    if set_u not in cheapest or cheapest[set_u][0] > w:
                        cheapest[set_u] = (w, u, v)
                    if set_v not in cheapest or cheapest[set_v][0] > w:
                        cheapest[set_v] = (w, u, v)
            for w, u, v in cheapest.values():
                if union(u, v):
                    mst.append((u, v, w))
                    total_weight += w
                    num_components -= 1
        print("\nMST (Boruvka's):")
        for u, v, w in mst:
            print(f"{u} -- {v}  weight = {w}")
        print("Total Weight:", total_weight, "\n")

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
        elif operation[0] == "BORUVKA":
            graph.MST_Boruvka()
        elif operation[0] == "DIJK":
            graph.ShortestPath(operation[1])
        inputs -= 1


if __name__ == "__main__":
    main()
