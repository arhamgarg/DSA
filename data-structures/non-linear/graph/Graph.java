import java.util.*;

class GraphAList {

    class Node {
        String value;
        ArrayList<Edge> adjList;

        Node(String e) {
            this.value = e;
            this.adjList = new ArrayList<>();
        }

        void addToAdjList(Edge e) {
            adjList.add(e);
        }
    }

    class Edge {
        Node v1, v2;
        int weight;

        Edge(Node v1, Node v2, int w) {
            this.v1 = v1;
            this.v2 = v2;
            this.weight = w;
        }
    }

    HashMap<String, Node> nodes;
    ArrayList<Edge> allEdges; // For Kruskal’s algorithm

    GraphAList() {
        nodes = new HashMap<>();
        allEdges = new ArrayList<>();
    }

    void insertNode(String e) {
        if (!nodes.containsKey(e)) {
            nodes.put(e, new Node(e));
        } else {
            System.out.println("Node already exists: " + e);
        }
    }

    void insertEdge(String v1, String v2, int w) {
        Node n1 = nodes.get(v1);
        Node n2 = nodes.get(v2);

        if (n1 == null || n2 == null) {
            System.out.println("Error: One or both nodes not found.");
            return;
        }

        // Create a new edge and add it to both nodes' adjacency lists
        Edge edge = new Edge(n1, n2, w);
        n1.addToAdjList(edge);
        n2.addToAdjList(edge);
        allEdges.add(edge);

        System.out.println("Edge inserted: " + v1 + " - " + v2 + " (w=" + w + ")");
    }

    Node getNode(String e) {
        return nodes.get(e);
    }

    void DFS(Node start) {
        if (start == null)
            return;

        HashSet<Node> visited = new HashSet<>();
        System.out.print("DFS Traversal: ");
        dfsHelper(start, visited);
        System.out.println();
    }

    void dfsHelper(Node node, HashSet<Node> visited) {
        visited.add(node);
        System.out.print(node.value + " ");

        for (Edge e : node.adjList) {
            Node neighbor = (e.v1 == node) ? e.v2 : e.v1; // Get the other node of the edge
            if (!visited.contains(neighbor)) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void BFS(Node start) {
        if (start == null)
            return;

        HashSet<Node> visited = new HashSet<>();
        Queue<Node> q = new LinkedList<>();
        q.add(start);
        visited.add(start);

        System.out.print("BFS Traversal: ");
        while (!q.isEmpty()) {
            Node curr = q.poll();
            System.out.print(curr.value + " ");

            // Add unvisited neighbors to the queue
            for (Edge e : curr.adjList) {
                Node neighbor = (e.v1 == curr) ? e.v2 : e.v1;// Get the other node of the edge
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    q.add(neighbor);
                }
            }
        }
        System.out.println();
    }

    void printGraph() {
        for (Node node : nodes.values()) {
            System.out.print("Node " + node.value + " -> ");
            for (Edge e : node.adjList) {
                Node neighbor = (e.v1 == node) ? e.v2 : e.v1; // Get the other node of the edge
                System.out.print(neighbor.value + "(w=" + e.weight + ") ");
            }
            System.out.println();
        }
    }

    void MST_prims(Node start) {
        if (start == null)
            return;

        // Stores nodes already included in MST
        HashSet<Node> inMST = new HashSet<>();

        // Stores minimum edge weight to each node
        Map<Node, Integer> key = new HashMap<>();

        // Stores parent of each node in MST
        Map<Node, Node> parent = new HashMap<>();

        for (Node n : nodes.values()) {
            key.put(n, Integer.MAX_VALUE);
            parent.put(n, null);
        }

        key.put(start, 0);

        // Min-priority queue based on smallest key value
        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(key::get));
        pq.add(start);

        while (!pq.isEmpty()) {
            Node u = pq.poll();
            if (inMST.contains(u))
                continue;
            inMST.add(u);

            for (Edge e : u.adjList) {
                Node v = (e.v1 == u) ? e.v2 : e.v1;
                int weight = e.weight;

                // If v not in MST and weight < current key
                if (!inMST.contains(v) && weight < key.get(v)) {
                    key.put(v, weight);
                    parent.put(v, u);
                    pq.add(v);
                }
            }
        }

        System.out.println("Prim’s MST edges:");
        int totalWeight = 0;
        for (Node n : nodes.values()) {
            Node p = parent.get(n);
            if (p != null) {
                int w = key.get(n);
                totalWeight += w;
                System.out.println(p.value + " - " + n.value + " (w=" + w + ")");
            }
        }
        System.out.println("Total weight = " + totalWeight);
    }

    class DisjointSet {
        Map<Node, Node> parent;
        Map<Node, Integer> rank;

        DisjointSet(Collection<Node> nodes) {
            parent = new HashMap<>();
            rank = new HashMap<>();
            for (Node node : nodes) {
                parent.put(node, node);
                rank.put(node, 0);
            }
        }

        Node find(Node i) {
            if (parent.get(i) != i)
                parent.put(i, find(parent.get(i)));
            return parent.get(i);
        }

        void union(Node i, Node j) {
            Node rootI = find(i);
            Node rootJ = find(j);
            if (rootI != rootJ) {
                if (rank.get(rootI) < rank.get(rootJ)) {
                    parent.put(rootI, rootJ);
                } else if (rank.get(rootJ) < rank.get(rootI)) {
                    parent.put(rootJ, rootI);
                } else {
                    parent.put(rootJ, rootI);
                    rank.put(rootI, rank.get(rootI) + 1);
                }
            }
        }
    }

    void MST_Kruskal() {
        Collections.sort(allEdges, Comparator.comparingInt(e -> e.weight));
        DisjointSet ds = new DisjointSet(nodes.values());

        ArrayList<Edge> result = new ArrayList<>();
        int totalWeight = 0;

        for (Edge edge : allEdges) {
            Node root1 = ds.find(edge.v1);
            Node root2 = ds.find(edge.v2);

            if (root1 != root2) {
                result.add(edge);
                totalWeight += edge.weight;
                ds.union(edge.v1, edge.v2);
            }
        }

        System.out.println("Kruskal’s MST edges:");
        for (Edge e : result) {
            System.out.println(e.v1.value + " - " + e.v2.value + " (w=" + e.weight + ")");
        }
        System.out.println("Total weight = " + totalWeight);
    }

    void ShortestPath(String startKey) {
        Node start = nodes.get(startKey);
        if (start == null)
            return;

        Map<Node, Integer> dist = new HashMap<>();
        Set<Node> visited = new HashSet<>();

        for (Node n : nodes.values())
            dist.put(n, Integer.MAX_VALUE);
        dist.put(start, 0);

        PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(dist::get));
        pq.add(start);

        while (!pq.isEmpty()) {
            Node curr = pq.poll();
            if (visited.contains(curr))
                continue;
            visited.add(curr);

            for (Edge e : curr.adjList) {
                Node neighbor = (e.v1 == curr) ? e.v2 : e.v1;
                int newDist = dist.get(curr) + e.weight;

                if (newDist < dist.get(neighbor)) {
                    dist.put(neighbor, newDist);
                    pq.add(neighbor);
                }
            }
        }

        System.out.println("Dijkstra Shortest Paths from " + start.value + ":");
        for (Map.Entry<Node, Integer> entry : dist.entrySet()) {
            System.out.println(start.value + " -> " + entry.getKey().value + " = " + entry.getValue());
        }
    }
}

public class Graph {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        GraphAList graph = new GraphAList();

        int inputs = Integer.parseInt(sc.nextLine());

        while (inputs-- > 0) {
            String command = sc.nextLine();
            String[] op = command.split(" ");

            switch (op[0]) {
                case "IN":
                    graph.insertNode(op[1]);
                    break;

                case "IE":
                    graph.insertEdge(op[1], op[2], Integer.parseInt(op[3]));
                    break;

                case "DFS":
                    graph.DFS(graph.getNode(op[1]));
                    break;

                case "BFS":
                    graph.BFS(graph.getNode(op[1]));
                    break;

                case "PRIM":
                    graph.MST_prims(graph.getNode(op[1]));
                    break;

                case "PG":
                    graph.printGraph();
                    break;

                case "DIJK":
                    graph.ShortestPath(op[1]);
                    break;

                case "KRUSKAL":
                    graph.MST_Kruskal();
                    break;

                default:
                    System.out.println("Invalid command");
            }
        }

        sc.close();
    }
}
