package main

import (
	"errors"
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
	newNode := &QueueNode{
		data: data,
	}
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

func (q *Queue) Dequeue() (int, error) {
	if q.head == nil {
		return 0, errors.New("queue is empty")
	}
	val := q.head.data
	q.head = q.head.next
	q.size--
	return val, nil
}

func (q *Queue) Front() (int, error) {
	if q.head == nil {
		return 0, errors.New("queue is empty")
	}
	return q.head.data, nil
}

func (q *Queue) Size() int {
	return q.size
}

func (q *Queue) IsEmpty() bool {
	return q.size == 0
}
