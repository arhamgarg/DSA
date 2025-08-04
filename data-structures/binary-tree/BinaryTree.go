package main

import "fmt"

type Node struct {
	data  int
	left  *Node
	right *Node
}

type BinaryTree struct {
	idx int
}

func (bt *BinaryTree) BuildTree(nodes []int) *Node {
	bt.idx++
	if nodes[bt.idx] == -1 {
		return nil
	}

	newNode := &Node{data: nodes[bt.idx]}
	newNode.left = bt.BuildTree(nodes)
	newNode.right = bt.BuildTree(nodes)

	return newNode
}

func preorder(root *Node) {
	if root == nil {
		return
	}
	fmt.Print(root.data, " ")
	preorder(root.left)
	preorder(root.right)
}

func inorder(root *Node) {
	if root == nil {
		return
	}
	inorder(root.left)
	fmt.Print(root.data, " ")
	inorder(root.right)
}

func postorder(root *Node) {
	if root == nil {
		return
	}
	postorder(root.left)
	postorder(root.right)
	fmt.Print(root.data, " ")
}

func levelorder(root *Node) {
	if root == nil {
		return
	}

	queue := []*Node{root}

	for len(queue) > 0 {
		level := len(queue)

		for i := 0; i < level; i++ {
			curr := queue[0]
			queue = queue[1:]
			fmt.Print(curr.data, " ")

			if curr.left != nil {
				queue = append(queue, curr.left)
			}
			if curr.right != nil {
				queue = append(queue, curr.right)
			}
		}
		fmt.Println()
	}
}
