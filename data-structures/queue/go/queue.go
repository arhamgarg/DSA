package main

import (
	"fmt"
)

type QueueNode struct {
	data int
	next *QueueNode
}

type Queue struct {
	head *QueueNode
	size int
}

func (q *Queue) Enqueue(data int) {
	newNode := &QueueNode{data: data}
	if q.head == nil {
		q.head = newNode
		q.size++
		return
	}

	curr := q.head
	for curr.next != nil {
		curr = curr.next
	}
	curr.next = newNode
	q.size++
}

func (q *Queue) Dequeue() int {
	if q.head == nil {
		fmt.Println("Queue is empty")
		return -1
	}
	val := q.head.data
	q.head = q.head.next
	q.size--
	return val
}

func (q *Queue) Front() int {
	if q.head == nil {
		fmt.Println("Queue is empty")
		return -1
	}
	return q.head.data
}

func (q *Queue) Size() int {
	return q.size
}

func (q *Queue) IsEmpty() bool {
	return q.size == 0
}

func main() {
	q := &Queue{}

	q.Enqueue(1)
	q.Enqueue(64)
	q.Enqueue(23)
	q.Enqueue(6)

	fmt.Println("Front:", q.Front())
	fmt.Println("Size:", q.Size())

	q.Dequeue()
	fmt.Println("Front:", q.Front())
	fmt.Println("Size:", q.Size())

	fmt.Println("Dequeue:", q.Dequeue()) // 64
	fmt.Println("Dequeue:", q.Dequeue()) // 23
	fmt.Println("Dequeue:", q.Dequeue()) // 6
	fmt.Println("Dequeue:", q.Dequeue()) // Queue is empty → -1
}
