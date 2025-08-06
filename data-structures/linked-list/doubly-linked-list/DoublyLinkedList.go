package main

import "fmt"

type Node struct {
	data int
	prev *Node
	next *Node
}

type DoublyLinkedList struct {
	head *Node
	tail *Node
}

func (dll *DoublyLinkedList) InsertFirst(data int) {
	newNode := &Node{data: data}

	if dll.head == nil {
		dll.head = newNode
		dll.tail = newNode
	} else {
		newNode.next = dll.head
		dll.head.prev = newNode
		dll.head = newNode
	}
}

func (dll *DoublyLinkedList) InsertLast(data int) {
	newNode := &Node{data: data}

	if dll.tail == nil {
		dll.head = newNode
		dll.tail = newNode
	} else {
		dll.tail.next = newNode
		newNode.prev = dll.tail
		dll.tail = newNode
	}
}

func (dll *DoublyLinkedList) DeleteFirst() {
	if dll.head == nil {
		fmt.Println("List is Empty")
		return
	}

	if dll.head == dll.tail {
		dll.head = nil
		dll.tail = nil
	} else {
		dll.head = dll.head.next
		dll.head.prev = nil
	}
}

func (dll *DoublyLinkedList) DeleteLast() {
	if dll.tail == nil {
		fmt.Println("List is Empty")
		return
	}

	if dll.head == dll.tail {
		dll.head = nil
		dll.tail = nil
	} else {
		dll.tail = dll.tail.prev
		dll.tail.next = nil
	}
}

func (dll *DoublyLinkedList) DisplayForward() {
	current := dll.head
	fmt.Print("Forward: ")
	for current != nil {
		fmt.Printf("%d ", current.data)
		current = current.next
	}
	fmt.Println()
}

func (dll *DoublyLinkedList) DisplayBackward() {
	current := dll.tail
	fmt.Print("Backward: ")
	for current != nil {
		fmt.Printf("%d ", current.data)
		current = current.prev
	}
	fmt.Println()
}
