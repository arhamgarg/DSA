package main

import (
    "fmt"
)

type StackNode struct {
    data int
    next * StackNode
}

type Stack struct {
    head * StackNode
    size int
}

func(s * Stack) Push(data int) {
    newNode: = & StackNode {
        data: data
    }
    newNode.next = s.head
    s.head = newNode
    s.size++
}

func(s * Stack) Pop() int {
    if s.head == nil {
        fmt.Println("Stack is empty")
        return -1
    }
    val: = s.head.data
    s.head = s.head.next
    s.size--
        return val
}

func(s * Stack) Top() int {
    if s.head == nil {
        fmt.Println("Stack is empty")
        return -1
    }
    return s.head.data
}

func(s * Stack) Size() int {
    return s.size
}

func(s * Stack) IsEmpty() bool {
    return s.size == 0
}
