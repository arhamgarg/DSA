#![allow(dead_code)]

// # Notes
// The stack is being implemented as a LinkedList using Nodes & Next pointers.
//
// Option<> enum is used to indicate there might or might not be a next node. It
// contains Some(T) or None
//
// Box<> is being used to allocate data directly on the heap. As a LL is an
// infinite recursion data structure, we cannot predict it's size during compile
// time. Rust needs to know the size of every type during compile time but a
// struct containing itself as a member would require infinite space.
//
// size(Node) = size(T) + size(Option<Node>)
// size(Node) = size(T) + size(size(Node) + Option<Node> ...)
//
// Wrapping up the Node inside a box means that we are storing a "pointer"
// of known fixed size. Additionally, Box<> automatically manages memory
// safety and deallocates when out of scope.

struct Node<T> {
    value: T,
    next: Option<Box<Node<T>>>,
}

pub struct Stack<T> {
    top: Option<Box<Node<T>>>,
    size: u32,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack { top: None, size: 0 }
    }

    fn push(&mut self, item: T) {
        let new_node = Box::new(Node {
            value: item,
            next: self.top.take(),
        });
        self.top = Some(new_node);
        self.size += 1;
    }

    fn pop(&mut self) -> Option<T> {
        self.top.take().map(|node| {
            self.top = node.next;
            self.size -= 1;
            node.value
        })
    }

    fn peek(&self) -> Option<&T> {
        self.top.as_ref().map(|node| &node.value)
    }

    fn is_empty(&self) -> bool {
        self.top.is_none()
    }

    fn size(&self) -> u32 {
        self.size
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new_stack_is_empty() {
        let stack: Stack<i32> = Stack::new();
        assert!(stack.is_empty());
    }

    #[test]
    fn test_push_and_pop() {
        let mut stack = Stack::new();
        stack.push(1);
        stack.push(2);
        assert_eq!(stack.pop(), Some(2));
        assert_eq!(stack.pop(), Some(1));
        assert_eq!(stack.pop(), None);
    }

    #[test]
    fn test_peek() {
        let mut stack = Stack::new();
        assert_eq!(stack.peek(), None);
        stack.push(5);
        assert_eq!(stack.peek(), Some(&5));
        stack.push(10);
        assert_eq!(stack.peek(), Some(&10));
        stack.pop();
        assert_eq!(stack.peek(), Some(&5));
    }

    #[test]
    fn test_is_empty() {
        let mut stack = Stack::new();
        assert!(stack.is_empty());
        stack.push(1);
        assert!(!stack.is_empty());
        stack.pop();
        assert!(stack.is_empty());
    }

    #[test]
    fn test_size() {
        let mut stack = Stack::new();
        assert_eq!(stack.size(), 0);
        stack.push(1);
        assert_eq!(stack.size(), 1);
        stack.pop();
        assert_eq!(stack.size(), 0);
    }
}
