package main

import (
    "fmt"
)

type QueueNode struct {
    data int
    next * QueueNode
}

type Queue struct {
    head * QueueNode
    size int
}

func(q * Queue) Enqueue(data int) {
    newNode := & QueueNode {
        data:data,
    }
    if q.head == nil {
        q.head = newNode
        q.size++
            return
    }

    curr:= q.head
    for curr.next != nil {
        curr = curr.next
    }
    curr.next = newNode
    q.size++
}

func(q * Queue) Dequeue() int {
    if q.head == nil {
        fmt.Println("Queue is empty")
        return -1
    }
    val:= q.head.data
    q.head = q.head.next
    q.size--
        return val
}

func(q * Queue) Front() int {
    if q.head == nil {
        fmt.Println("Queue is empty")
        return -1
    }
    return q.head.data
}

func(q * Queue) Size() int {
    return q.size
}

func(q * Queue) IsEmpty() bool {
    return q.size == 0
}
