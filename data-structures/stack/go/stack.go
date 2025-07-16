package main

import (
	"fmt"
)

type StackNode struct {
	data int
	next *StackNode
}

type Stack struct {
	head *StackNode
	size int
}

func (s *Stack) Push(data int) {
	newNode := &StackNode{data: data}
	newNode.next = s.head
	s.head = newNode
	s.size++
}

func (s *Stack) Pop() int {
	if s.head == nil {
		fmt.Println("Stack is empty")
		return -1
	}
	val := s.head.data
	s.head = s.head.next
	s.size--
	return val
}

func (s *Stack) Top() int {
	if s.head == nil {
		fmt.Println("Stack is empty")
		return -1
	}
	return s.head.data
}

func (s *Stack) Size() int {
	return s.size
}

func (s *Stack) IsEmpty() bool {
	return s.size == 0
}

func main() {
	stack := &Stack{}

	stack.Push(23)
	stack.Push(6)
	stack.Push(69)
	stack.Push(64)
	stack.Push(1)
	stack.Push(4)
	stack.Push(47)

	fmt.Println("Top:", stack.Top())
	fmt.Println("Pop:", stack.Pop())
	fmt.Println("Pop:", stack.Pop())
	fmt.Println("Size:", stack.Size())
	fmt.Println("Empty or Not:", stack.IsEmpty())
}
