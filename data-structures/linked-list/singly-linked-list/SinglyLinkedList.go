package main

import "fmt"

type Node struct {
	data int
	next *Node
}

type LinkedList struct {
	head *Node
}

func (ll *LinkedList) AddFront(data int) {
	newNode := &Node{data: data, next: ll.head}

	if(ll.head == nil){
		ll.head = newNode
		return
	}
	newNode.next = ll.head
	ll.head = newNode
}

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

func (ll *LinkedList) DeleteFront() {
	if ll.head == nil {
		fmt.Println("List is empty.")
		return
	}
	ll.head = ll.head.next
}

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
