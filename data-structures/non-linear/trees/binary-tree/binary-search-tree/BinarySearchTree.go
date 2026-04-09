package main

import "fmt"

type Node struct {
	data  int
	left  *Node
	right *Node
}

func insert(root *Node, data int) *Node {
	if root == nil {
		return &Node{data: data}
	}

	if root.data > data {
		root.left = insert(root.left, data)
	} else {
		root.right = insert(root.right, data)
	}
	return root
}

func buildTree(datas []int) *Node {
	var root *Node
	for i := 0; i < len(datas); i++ {
		root = insert(root, datas[i])
	}
	return root
}

func inorder(root *Node) {
	if root == nil {
		return
	}
	inorder(root.left)
	fmt.Print(root.data, " ")
	inorder(root.right)
}

func search(root *Node, key int) bool {
	if root == nil {
		return false
	}
	if root.data == key {
		return true
	}
	if root.data > key {
		return search(root.left, key)
	}
	return search(root.right, key)
}

func inorderSuccessor(root *Node) *Node {
	for root.left != nil {
		root = root.left
	}
	return root
}

func deleteNode(root *Node, key int) *Node {
	if root == nil {
		return nil
	}

	if root.data > key {
		root.left = deleteNode(root.left, key)
	} else if root.data < key {
		root.right = deleteNode(root.right, key)
	} else {
		if root.left == nil && root.right == nil {
			return nil
		}
		if root.left == nil {
			return root.right
		} else if root.right == nil {
			return root.left
		}
		IS := inorderSuccessor(root.right)
		root.data = IS.data
		root.right = deleteNode(root.right, IS.data)
	}
	return root
}
