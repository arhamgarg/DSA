package main

import "fmt"

func dfs(graph map[string][]string, start string, visited map[string]bool) {
	visited[start] = true // mark current node as visited

	fmt.Println(start)

	for _, neighbour := range graph[start] {
		if !visited[neighbour] {
			dfs(graph, neighbour, visited)
		}
	}
}

func main() {
	graph := map[string][]string{
		"A": {"B", "C"},
		"B": {"D", "E"},
		"C": {"F"},
		"D": {},
		"E": {"F"},
		"F": {},
	}

	visited := make(map[string]bool)
	dfs(graph, "A", visited)
}
