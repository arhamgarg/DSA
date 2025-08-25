package main

import (
	"errors"
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
	newNode := &StackNode{
		data: data,
	}
	newNode.next = s.head
	s.head = newNode
	s.size++
}

func (s *Stack) Pop() (int, error) {
	if s.head == nil {
		return 0, errors.New("stack is empty")
	}
	val := s.head.data
	s.head = s.head.next
	s.size--
	return val, nil
}

func (s *Stack) Top() (int, error) {
	if s.head == nil {
		return 0, errors.New("stack is empty")
	}
	return s.head.data, nil
}

func (s *Stack) Size() int {
	return s.size
}

func (s *Stack) IsEmpty() bool {
	return s.size == 0
}
