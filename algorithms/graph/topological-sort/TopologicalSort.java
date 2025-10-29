import java.util.*;
import java.util.Stack;

class Graph {
  int V;
  List<Integer>[] adj;

  public Graph(int V) {
    this.V = V;
    adj = new ArrayList[V];
    for (int i = 0; i < V; i++) {
      adj[i] = new ArrayList<>();
    }
  }

  void addEdge(int u, int v) {
    adj[u].add(v);
  }

  private void dfs(int u, boolean[] visited, Stack<Integer> stack) {
    visited[u] = true;

    for (int v : adj[u]) {
      if (!visited[v]) {
        dfs(v, visited, stack);
      }
    }

    stack.push(u);
  }

  void topologicalSort() {
    boolean[] visited = new boolean[V];
    Stack<Integer> stack = new Stack<>();

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        dfs(i, visited, stack);
      }
    }

    while (!stack.isEmpty()) {
      System.out.print(stack.pop() + " ");
    }

    System.out.println();
  }
}
