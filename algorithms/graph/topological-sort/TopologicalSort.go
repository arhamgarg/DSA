package main

import "fmt"

type Graph struct {
	V   int
	adj [][]int
}

func NewGraph(V int) *Graph {
	graph := &Graph{
		V:   V,
		adj: make([][]int, V),
	}
	for i := 0; i < V; i++ {
		graph.adj[i] = []int{}
	}
	return graph
}

func (g *Graph) AddEdge(u, v int) {
	g.adj[u] = append(g.adj[u], v)
}

func (g *Graph) dfs(u int, visited []bool, stack *[]int) {
	visited[u] = true

	for _, v := range g.adj[u] {
		if !visited[v] {
			g.dfs(v, visited, stack)
		}
	}

	*stack = append(*stack, u)
}

func (g *Graph) TopologicalSort() {
	visited := make([]bool, g.V)
	var stack []int

	for i := 0; i < g.V; i++ {
		if !visited[i] {
			g.dfs(i, visited, &stack)
		}
	}

	for i := len(stack) - 1; i >= 0; i-- {
		fmt.Printf("%d ", stack[i])
	}
	fmt.Println()
}

