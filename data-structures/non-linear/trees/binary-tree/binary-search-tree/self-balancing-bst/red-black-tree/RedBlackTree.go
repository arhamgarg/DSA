package main

import "fmt"

type Node struct {
	data   int
	color  string
	left   *Node
	right  *Node
	parent *Node
}

type RedBlackTree struct {
	root *Node
	NIL  *Node
}

func NewRedBlackTree() *RedBlackTree {
	nilNode := &Node{
		data:  0,
		color: "BLACK",
	}

	nilNode.left = nilNode
	nilNode.right = nilNode

	return &RedBlackTree{
		root: nilNode,
		NIL:  nilNode,
	}
}

func (t *RedBlackTree) rotateLeft(x *Node) {
	y := x.right
	x.right = y.left

	if y.left != t.NIL {
		y.left.parent = x
	}

	y.parent = x.parent

	if x.parent == nil {
		t.root = y
	} else if x == x.parent.left {
		x.parent.left = y
	} else {
		x.parent.right = y
	}

	y.left = x
	x.parent = y
}

func (t *RedBlackTree) rotateRight(x *Node) {
	y := x.left
	x.left = y.right

	if y.right != t.NIL {
		y.right.parent = x
	}

	y.parent = x.parent

	if x.parent == nil {
		t.root = y
	} else if x == x.parent.right {
		x.parent.right = y
	} else {
		x.parent.left = y
	}

	y.right = x
	x.parent = y
}

func (t *RedBlackTree) fixInsert(k *Node) {
	for k != t.root && k.parent.color == "RED" {
		if k.parent == k.parent.parent.left {
			u := k.parent.parent.right
			if u.color == "RED" {
				k.parent.color = "BLACK"
				u.color = "BLACK"
				k.parent.parent.color = "RED"
				k = k.parent.parent
			} else {
				if k == k.parent.right {
					k = k.parent
					t.rotateLeft(k)
				}
				k.parent.color = "BLACK"
				k.parent.parent.color = "RED"
				t.rotateRight(k.parent.parent)
			}
		} else {
			u := k.parent.parent.left
			if u.color == "RED" {
				k.parent.color = "BLACK"
				u.color = "BLACK"
				k.parent.parent.color = "RED"
				k = k.parent.parent
			} else {
				if k == k.parent.left {
					k = k.parent
					t.rotateRight(k)
				}
				k.parent.color = "BLACK"
				k.parent.parent.color = "RED"
				t.rotateLeft(k.parent.parent)
			}
		}
	}
	t.root.color = "BLACK"
}

func (t *RedBlackTree) Insert(data int) {
	newNode := &Node{
		data:  data,
		color: "RED",
		left:  t.NIL,
		right: t.NIL,
	}

	var parent *Node
	current := t.root

	for current != t.NIL {
		parent = current
		if newNode.data < current.data {
			current = current.left
		} else {
			current = current.right
		}
	}

	newNode.parent = parent

	if parent == nil {
		t.root = newNode
	} else if newNode.data < parent.data {
		parent.left = newNode
	} else {
		parent.right = newNode
	}

	if newNode.parent == nil {
		newNode.color = "BLACK"
		return
	}

	if newNode.parent.parent == nil {
		return
	}

	t.fixInsert(newNode)
}

func (t *RedBlackTree) InorderTraversal(node *Node) {
	if node != t.NIL {
		t.InorderTraversal(node.left)
		fmt.Printf("%d ", node.data)
		t.InorderTraversal(node.right)
	}
}

func (t *RedBlackTree) Search(node *Node, data int) *Node {
	if node == t.NIL || node.data == data {
		return node
	}

	if data < node.data {
		return t.Search(node.left, data)
	}

	return t.Search(node.right, data)
}
