package main

import (
	"errors"
)

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

func (dq *Deque) PopFront() (int, error) {
	if dq.IsEmpty() {
		return 0, errors.New("deque is empty")
	}
	data := dq.front.data
	if dq.front == dq.rear {
		dq.front = nil
		dq.rear = nil
	} else {
		dq.front = dq.front.next
		dq.front.prev = nil
	}
	return data, nil
}

func (dq *Deque) PopRear() (int, error) {
	if dq.IsEmpty() {
		return 0, errors.New("deque is empty")
	}
	data := dq.rear.data
	if dq.front == dq.rear {
		dq.front = nil
		dq.rear = nil
	} else {
		dq.rear = dq.rear.prev
		dq.rear.next = nil
	}
	return data, nil
}

func (dq *Deque) PeekFront() (int, error) {
	if dq.IsEmpty() {
		return 0, errors.New("deque is empty")
	}
	return dq.front.data, nil
}

func (dq *Deque) PeekRear() (int, error) {
	if dq.IsEmpty() {
		return 0, errors.New("deque is empty")
	}
	return dq.rear.data, nil
}
