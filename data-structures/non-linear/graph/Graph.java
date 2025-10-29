import java.util.*;

class Node {
    String value;
    List<Edge> adjList;

    Node(String vertex) {
        this.value = vertex;
        adjList = new ArrayList<>();
    }

    void addEdge(Edge e) {
        adjList.add(e);
    }
}

class Edge {
    Node n1;
    Node n2;
    int wt;

    Edge(Node n1, Node n2, int wt) {
        this.n1 = n1;
        this.n2 = n2;
        this.wt = wt;
    }
}

class NodeDist {
    String node;
    int distance;

    NodeDist(String node, int distance) {
        this.node = node;
        this.distance = distance;
    }
}

class Helper {
    int wt;
    Node node;
    Node parent;

    public Helper(int wt, Node node, Node parent) {
        this.wt = wt;
        this.node = node;
        this.parent = parent;

    }
}

class DisjointSet {
    Map<String, String> parent = new HashMap<>();
    Map<String, Integer> size = new HashMap<>();

    DisjointSet(Set<String> vertices) {
        for (String v : vertices) {
            parent.put(v, v);
            size.put(v, 1);
        }
    }

    String findParent(String node) {
        if (parent.get(node).equals(node))
            return node;
        String ultimateParent = findParent(parent.get(node));
        parent.put(node, ultimateParent);
        return ultimateParent;
    }

    void unionBySize(String u, String v) {
        String ultU = findParent(u);
        String ultV = findParent(v);
        if (ultU.equals(ultV))
            return;

        int sizeU = size.get(ultU);
        int sizeV = size.get(ultV);

        if (sizeU < sizeV) {
            parent.put(ultU, ultV);
            size.put(ultV, sizeU + sizeV);
        } else {
            parent.put(ultV, ultU);
            size.put(ultU, sizeU + sizeV);
        }
    }
}

public class Graph {
    Map<String, Node> nodes;

    public Graph() {
        this.nodes = new HashMap<>();
    }

    public void insertNode(String s) {
        if (!nodes.containsKey(s)) {
            nodes.put(s, new Node(s));
        }
    }

    public void insertEdge(String s1, String s2, int wt) {
        Node n1 = nodes.get(s1);
        Node n2 = nodes.get(s2);
        if (n1 == null || n2 == null) {
            System.out.println("Error: Node not found for edge " + s1 + " - " + s2);
            return;
        }
        for (Edge e : n1.adjList) {
            if (e.n2 == n2)
                return;
        }
        n1.addEdge(new Edge(n1, n2, wt));
        n2.addEdge(new Edge(n2, n1, wt));
    }

    public Node getNode(String s) {
        return nodes.get(s);
    }

    public void BFS(Node n) {
        HashSet<Node> visited = new HashSet<>();
        Queue<Node> q = new ArrayDeque<>();
        visited.add(n);
        q.add(n);
        while (!q.isEmpty()) {
            Node node = q.poll();
            System.out.print(node.value + " ");
            for (Edge e : node.adjList) {
                if (!visited.contains(e.n2)) {
                    visited.add(e.n2);
                    q.add(e.n2);
                }
            }
        }
        System.out.println();
    }

    public void DFS(Node n) {
        HashSet<Node> visited = new HashSet<>();
        DFSHelper(n, visited);
        System.out.println();

    }

    void DFSHelper(Node n, HashSet<Node> visited) {
        if (n == null || visited.contains(n))
            return;
        visited.add(n);
        System.out.print(n.value + " ");
        for (Edge e : n.adjList) {
            DFSHelper(e.n2, visited);
        }
    }

    void printGraph() {
        for (String s : nodes.keySet()) {
            Node node = nodes.get(s);
            System.out.print(node.value + "-> ");
            for (Edge e : node.adjList) {
                System.out.print("(" + e.n2.value + "," + e.wt + ") ");
            }
            System.out.println();
        }
    }

    public Map<String, Integer> Dijkstra(Node start) {
        Map<String, Integer> dist = new HashMap<>();
        Set<String> visited = new HashSet<>();
        for (String node : nodes.keySet()) {
            dist.put(node, Integer.MAX_VALUE);
        }
        dist.put(start.value, 0);
        PriorityQueue<NodeDist> pq = new PriorityQueue<>(Comparator.comparingInt(n -> n.distance));
        pq.add(new NodeDist(start.value, 0));
        while (!pq.isEmpty()) {
            NodeDist d = pq.poll();
            String s = d.node;
            if (visited.contains(s)) {
                continue;
            }
            visited.add(s);
            int distance = d.distance;

            for (Edge e : nodes.get(s).adjList) {
                String adjNode = e.n2.value;
                int adjWt = e.wt;

                if (distance + adjWt < dist.get(adjNode)) {
                    dist.put(adjNode, distance + adjWt);
                    pq.add(new NodeDist(adjNode, distance + adjWt));
                }
            }
        }
        return dist;
    }

    public int Prims(Node start) {
        PriorityQueue<Helper> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a.wt));
        HashSet<Node> visited = new HashSet<>();

        int sum = 0;
        ArrayList<String[]> MST = new ArrayList<>();

        pq.add(new Helper(0, start, null));
        while (!pq.isEmpty()) {
            Helper top = pq.poll();
            int weight = top.wt;
            Node node = top.node;
            Node parent = top.parent;

            if (!visited.contains(node)) {
                visited.add(node);
                sum += weight;

                if (parent != null)
                    MST.add(new String[] { parent.value, node.value });

                for (Edge e : node.adjList) {
                    Node ver = e.n2;
                    int wt = e.wt;
                    if (!visited.contains(e.n2))
                        pq.add(new Helper(wt, ver, node));
                }
            }

        }
        System.out.println("Edges in MST:");
        for (String[] edge : MST)
            System.out.println(edge[0] + " - " + edge[1]);

        return sum;
    }

    public int Kruskal() {
        List<Edge> edges = new ArrayList<>();
        Set<String> seen = new HashSet<>();

        for (Node n : nodes.values()) {
            for (Edge e : n.adjList) {
                String key1 = n.value + "-" + e.n2.value;
                String key2 = e.n2.value + "-" + n.value;
                if (!seen.contains(key1) && !seen.contains(key2)) {
                    edges.add(e);
                    seen.add(key1);
                }
            }
        }

        edges.sort(Comparator.comparingInt(a -> a.wt));

        DisjointSet ds = new DisjointSet(nodes.keySet());
        int sum = 0;
        ArrayList<String[]> mstEdges = new ArrayList<>();

        for (Edge e : edges) {
            String u = e.n1.value;
            String v = e.n2.value;
            int wt = e.wt;

            if (!ds.findParent(u).equals(ds.findParent(v))) {
                sum += wt;
                mstEdges.add(new String[] { u, v });
                ds.unionBySize(u, v);
            }
        }

        System.out.println("Edges in MST:");
        for (String[] edge : mstEdges)
            System.out.println(edge[0] + " - " + edge[1]);

        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Graph graph = new Graph();

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
                    System.out.println("Total MST Weight: " + graph.Prims(graph.getNode(op[1])));
                    break;

                case "PG":
                    graph.printGraph();
                    break;

                case "DIJK":
                    System.out.println(graph.Dijkstra(graph.getNode(op[1])));
                    break;

                case "KRUSKAL":
                    System.out.println("Total MST Weight: " + graph.Kruskal());
                    break;

                default:
                    System.out.println("Invalid command");
            }

        }

        sc.close();
    }
}