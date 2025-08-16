package main

import "fmt"

type Node struct {
	data int
	prev *Node
	next *Node
}

type Deque struct {
	front *Node
	rear  *Node
}

func (dq *Deque) IsEmpty() bool {
	return dq.front == nil
}

func (dq *Deque) AddFront(data int) {
	newNode := &Node{data: data}
	if dq.IsEmpty() {
		dq.front = newNode
		dq.rear = newNode
	} else {
		newNode.next = dq.front
		dq.front.prev = newNode
		dq.front = newNode
	}
}

func (dq *Deque) AddRear(data int) {
	newNode := &Node{data: data}
	if dq.IsEmpty() {
		dq.front = newNode
		dq.rear = newNode
	} else {
		dq.rear.next = newNode
		newNode.prev = dq.rear
		dq.rear = newNode
	}
}

func (dq *Deque) DeleteFront() {
	if dq.IsEmpty() {
		fmt.Println("Deque is empty")
		return
	}
	if dq.front == dq.rear {
		dq.front = nil
		dq.rear = nil
	} else {
		dq.front = dq.front.next
		dq.front.prev = nil
	}
}

func (dq *Deque) DeleteRear() {
	if dq.IsEmpty() {
		fmt.Println("Deque is empty")
		return
	}
	if dq.front == dq.rear {
		dq.front = nil
		dq.rear = nil
	} else {
		dq.rear = dq.rear.prev
		dq.rear.next = nil
	}
}

func (dq *Deque) PeekFront() int {
	if dq.IsEmpty() {
		panic("Deque is empty")
	}
	return dq.front.data
}

func (dq *Deque) PeekRear() int {
	if dq.IsEmpty() {
		panic("Deque is empty")
	}
	return dq.rear.data
}
