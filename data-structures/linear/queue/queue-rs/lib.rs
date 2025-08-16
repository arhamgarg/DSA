#![allow(dead_code)]

struct Node<T> {
    data: T,
    next: Option<Box<Node<T>>>,
}

// In the rear, we are using raw pointers instead of Option<> for efficient
// tail insertions. Additionally, as there is no access involved, there is
// no need for us to use Option<Box<Node<T>>> and incur the malloc cost
struct Queue<T> {
    front: Option<Box<Node<T>>>,
    rear: *mut Node<T>,
    len: usize,
}

impl<T> Queue<T> {
    fn new() -> Self {
        Queue {
            front: None,
            rear: std::ptr::null_mut(),
            len: 0,
        }
    }

    fn is_empty(&self) -> bool {
        self.len == 0
    }

    fn len(&self) -> usize {
        self.len
    }

    fn enqueue(&mut self, value: T) {
        let mut new_node = Box::new(Node {
            data: value,
            next: None,
        });

        let node_ptr: *mut _ = &mut *new_node;

        if self.is_empty() {
            self.front = Some(new_node);
            self.rear = node_ptr;
        } else {
            // As we are dereferencing a pointer and assuming that it is not a
            // dangling pointer, null or unaligned; it's an unsafe operation.
            // This works only because Queue is not empty but Rust generally
            // disallows it so we need to wrap it in unsafe{}.
            unsafe {
                (*self.rear).next = Some(new_node);
                self.rear = node_ptr;
            }
        }
        self.len += 1
    }

    // During dequeue, we are using Option<T> and not Option<&T> because we
    // are giving the owernship of the value to the accessor and are moving
    // it out of the data structure
    fn dequeue(&mut self) -> Option<T> {
        self.front.take().map(|front_node| {
            self.front = front_node.next;
            if self.front.is_none() {
                self.rear = std::ptr::null_mut();
            }
            self.len -= 1;
            front_node.data
        })
    }

    // The return type here is an Option<&T> because we do not want to transfer
    // ownership of this element and move it out of the data structure. Instead
    // we would like to borrow the value (READ-ONLY access).
    fn front(&self) -> Option<&T> {
        self.front.as_ref().map(|node| &node.data)
    }

    fn rear(&self) -> Option<&T> {
        if self.rear.is_null() {
            None
        } else {
            // Here, we are dereferencing a pointer to the rear Node and
            // extracting it's data but this is generally unsafe as the
            // pointer can be null or dangling
            unsafe { Some(&(*self.rear).data) }
        }
    }

    fn clear(&mut self) {
        // We are constantly calling the dequeue method till there is_some()
        // element returned during dequeue operation. As dequeue returns an
        // Option<> which can be Some(T) or None; if it resolves to None, then
        // the loop breaks
        while self.dequeue().is_some() {}
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new_queue_is_empty() {
        let q: Queue<i32> = Queue::new();
        assert!(q.is_empty());
        assert_eq!(q.len(), 0);
        assert_eq!(q.front(), None);
        assert_eq!(q.rear(), None);
    }

    #[test]
    fn test_enqueue() {
        let mut q = Queue::new();

        q.enqueue(10);
        assert!(!q.is_empty());
        assert_eq!(q.len(), 1);
        assert_eq!(q.front(), Some(&10));
        assert_eq!(q.rear(), Some(&10));

        q.enqueue(20);
        assert!(!q.is_empty());
        assert_eq!(q.len(), 2);
        assert_eq!(q.front(), Some(&10));
        assert_eq!(q.rear(), Some(&20));
    }

    #[test]
    fn test_dequeue() {
        let mut q = Queue::new();
        assert_eq!(q.dequeue(), None);

        q.enqueue(10);
        q.enqueue(20);

        assert_eq!(q.dequeue(), Some(10));
        assert_eq!(q.len(), 1);
        assert_eq!(q.front(), Some(&20));
        assert_eq!(q.rear(), Some(&20));

        assert_eq!(q.dequeue(), Some(20));
        assert!(q.is_empty());
        assert_eq!(q.front(), None);
        assert_eq!(q.rear(), None);
        assert_eq!(q.dequeue(), None)
    }

    #[test]
    fn test_front_and_rear_peek() {
        let mut q = Queue::new();
        assert_eq!(q.front(), None);
        assert_eq!(q.rear(), None);

        q.enqueue(5);
        assert_eq!(q.front(), Some(&5));
        assert_eq!(q.rear(), Some(&5));
    }

    #[test]
    fn test_clear() {
        let mut q = Queue::new();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        assert_eq!(q.len(), 3);

        q.clear();

        assert!(q.is_empty());
        assert_eq!(q.len(), 0);
        assert_eq!(q.front(), None);
        assert_eq!(q.rear(), None);
    }
}
