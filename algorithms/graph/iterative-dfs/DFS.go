package main

import "fmt"

func iterDfs(graph map[string][]string, start string) {
	visited := make(map[string]bool)

	// Using slice as stack to simulate behavior
	stack := []string{start}

	for len(stack) > 0 {
		n := len(stack) - 1
		node := stack[n]
		stack = stack[:n]

		if visited[node] {
			continue
		}

		// For unvisited node ... finding neighbours and pushing them
		// into slice in reverse order to retain FIFO behavior when grabbing
		// the rear element in subsequent iteration
		visited[node] = true
		fmt.Println(node)
		neighbours := graph[node]

		for i := len(neighbours) - 1; i >= 0; i-- {
			neighbour := neighbours[i]

			if !visited[neighbour] {
				stack = append(stack, neighbour)
			}
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

	iterDfs(graph, "A")
}
