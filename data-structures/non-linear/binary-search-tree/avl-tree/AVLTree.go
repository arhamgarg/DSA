package main

import "fmt"


type Node struct {
	data   int
	left   *Node
	right  *Node
	height int
}

type AVLTree struct {
	root *Node
}

func (tree *AVLTree) Insert(value int) {
	tree.root = insertNode(tree.root, value)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func height(node *Node) int {
	if node == nil {
		return 0
	}
	return node.height
}

func balanceFactor(node *Node) int {
	if node == nil {
		return 0
	}
	return height(node.left) - height(node.right)
}

func rightRotate(y *Node) *Node {
	x := y.left
	T2 := x.right

	x.right = y
	y.left = T2

	y.height = max(height(y.left), height(y.right)) + 1
	x.height = max(height(x.left), height(x.right)) + 1

	return x
}

func leftRotate(x *Node) *Node {
	y := x.right
	T2 := y.left

	y.left = x
	x.right = T2

	x.height = max(height(x.left), height(x.right)) + 1
	y.height = max(height(y.left), height(y.right)) + 1

	return y
}

func insertNode(node *Node, value int) *Node {
	if node == nil {
		return &Node{data: value, height: 1}
	}

	if value < node.data {
		node.left = insertNode(node.left, value)
	} else if value > node.data {
		node.right = insertNode(node.right, value)
	} else {
		return node
	}

	node.height = 1 + max(height(node.left), height(node.right))

	balance := balanceFactor(node)

	// Left Left
	if balance > 1 && value < node.left.data {
		return rightRotate(node)
	}

	// Right Right
	if balance < -1 && value > node.right.data {
		return leftRotate(node)
	}

	// Left Right
	if balance > 1 && value > node.left.data {
		node.left = leftRotate(node.left)
		return rightRotate(node)
	}

	// Right Left
	if balance < -1 && value < node.right.data {
		node.right = rightRotate(node.right)
		return leftRotate(node)
	}

	return node
}

func inorder(root *Node) {
	if root == nil {
		return
	}
	inorder(root.left)
	fmt.Print(root.data, " ")
	inorder(root.right)
}

func (tree *AVLTree) Inorder() {
	inorder(tree.root)
	fmt.Println()
}
