package main

import "fmt"

func bfs(graph map[string][]string, start string) {
	visited := make(map[string]bool)

	queue := []string{start}
	visited[start] = true

	fmt.Println("Traversal START")

	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		// Dequeue nodes and print them
		fmt.Println(node)

		for _, neighbor := range graph[node] {
			// Enqueue univisted neighbours
			if !visited[neighbor] {
				visited[neighbor] = true
				queue = append(queue, neighbor)
			}
		}
	}

	fmt.Println("Traversal DONE")
}

func main() {
	graph := map[string][]string{
		"Home":    {"Library", "Cafe"},
		"Library": {"Home", "Gym", "Office"},
		"Cafe":    {"Home", "Park"},
		"Gym":     {"Library"},
		"Office":  {"Library", "Mall"},
		"Park":    {"Cafe", "Mall"},
		"Mall":    {"Office", "Park", "Station"},
		"Station": {"Mall"},
	}

	bfs(graph, "Station")
}
