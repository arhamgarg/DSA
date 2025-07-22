package main

import "fmt"

// Node represents a single node in the list
type Node struct {
	data int
	next *Node
	// * is given so that the code will work on the actual object not a copy
}

type LinkedList struct {
	head *Node
}

// AddFront adds a node to the front of the list
func (ll *LinkedList) AddFront(data int) {
	newNode := &Node{data: data, next: ll.head}
	// & is used to get the memory address of the variable

	if(ll.head == nil){
		ll.head = newNode
		return
	}
	newNode.next = ll.head
	ll.head = newNode
}

// AddBack adds a node to the end of the list
func (ll *LinkedList) AddBack(data int) {
	newNode := &Node{data: data}

	if ll.head == nil {
		ll.head = newNode
		return
	}

	curr := ll.head
	for curr.next != nil {
		curr = curr.next
	}
	curr.next = newNode
}

// DeleteFront removes the first node of the list
func (ll *LinkedList) DeleteFront() {
	if ll.head == nil {
		fmt.Println("List is empty.")
		return
	}
	ll.head = ll.head.next
}

// DeleteBack removes the last node of the list
func (ll *LinkedList) DeleteBack() {
	if ll.head == nil {
		fmt.Println("List is empty.")
		return
	}
	if ll.head.next == nil {
		ll.head = nil
		return
	}

	curr := ll.head
	for curr.next.next != nil {
		curr = curr.next
	}
	curr.next = nil
}

// Search checks if a value exists in the list
func (ll *LinkedList) Search(value int) bool {
	curr := ll.head
	for curr != nil {
		if curr.data == value {
			return true
		}
		curr = curr.next
	}
	return false
}

// Print displays all elements of the list
func (ll *LinkedList) Print() {
	curr := ll.head
	if curr == nil {
		fmt.Println("List is empty.")
		return
	}
	for curr != nil {
		fmt.Print(curr.data, " -> ")
		curr = curr.next
	}
	fmt.Println("nil")
}

// InsertAt inserts a node at the given position
func (ll *LinkedList) InsertAt(position int, data int) {
	newNode := &Node{data: data}

	if position == 0 {
		newNode.next = ll.head
		ll.head = newNode
		return
	}

	curr := ll.head
	for i := 0; i < position-1 && curr != nil; i++ {
		curr = curr.next
	}

	if curr == nil {
		fmt.Println("Position out of bounds")
		return
	}

	newNode.next = curr.next
	curr.next = newNode
}
