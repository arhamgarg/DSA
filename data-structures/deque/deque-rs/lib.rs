#![allow(dead_code)]

struct Node<T> {
    data: T,
    prev: Option<*mut Node<T>>,
    next: Option<*mut Node<T>>,
}

struct Deque<T> {
    front: Option<*mut Node<T>>,
    back: Option<*mut Node<T>>,
    len: usize,
}

impl<T> Deque<T> {
    fn new() -> Self {
        Deque {
            front: None,
            back: None,
            len: 0,
        }
    }

    fn is_empty(&self) -> bool {
        self.len == 0
    }

    fn len(&self) -> usize {
        self.len
    }

    fn push_front(&mut self, data: T) {
        // Construct a new front node whose previous is none and next is the
        // head of the queue and the connecting it to the queue.
        let new_node: *mut _ = Box::into_raw(Box::new(Node {
            data,
            prev: None,
            next: self.front, // copy the pointer, Copy trait is borrowing
        }));

        unsafe {
            if let Some(front_ptr) = self.front {
                (*front_ptr).prev = Some(new_node);
            } else {
                // If the queue did not have any front node (empty queue)
                // the back also points to the same new node
                self.back = Some(new_node);
            }
        }
        self.front = Some(new_node);
        self.len += 1;
    }

    fn push_back(&mut self, data: T) {
        let new_node: *mut _ = Box::into_raw(Box::new(Node {
            data,
            prev: self.back, // copy the pointer, Copy trait is borrowing
            next: None,
        }));

        unsafe {
            if let Some(back_ptr) = self.back {
                (*back_ptr).next = Some(new_node);
            } else {
                // If the queue did not have any back node (empty queue)
                // the front also points to the same new node
                self.front = Some(new_node);
            }
        }

        self.back = Some(new_node);
        self.len += 1
    }

    fn pop_front(&mut self) -> Option<T> {
        self.front.map(|front_ptr| unsafe {
            let boxed_front = Box::from_raw(front_ptr);
            self.front = boxed_front.next;

            if let Some(new_front_ptr) = self.front {
                (*new_front_ptr).prev = None
            } else {
                self.back = None
            }
            self.len -= 1;
            boxed_front.data
        })
    }

    fn pop_back(&mut self) -> Option<T> {
        self.back.map(|back_ptr| unsafe {
            let boxed_back = Box::from_raw(back_ptr);
            self.back = boxed_back.prev;

            if let Some(new_back_ptr) = self.back {
                (*new_back_ptr).next = None;
            } else {
                self.front = None;
            }
            self.len -= 1;
            boxed_back.data
        })
    }

    fn front(&self) -> Option<&T> {
        self.front.map(|front_ptr| unsafe { &(*front_ptr).data })
    }

    fn back(&self) -> Option<&T> {
        self.back.map(|back_ptr| unsafe { &(*back_ptr).data })
    }

    fn clear(&mut self) {
        while self.pop_back().is_some() {}
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new_is_empty() {
        let deque: Deque<i32> = Deque::new();
        assert!(deque.is_empty());
        assert_eq!(deque.len(), 0);
        assert_eq!(deque.front(), None);
        assert_eq!(deque.back(), None);
    }

    #[test]
    fn test_push_front_and_front_back_access() {
        let mut deque = Deque::new();

        deque.push_front(10);
        assert_eq!(deque.len(), 1);
        assert_eq!(deque.front(), Some(&10));
        assert_eq!(deque.back(), Some(&10));

        deque.push_front(20);
        assert_eq!(deque.len(), 2);
        assert_eq!(deque.front(), Some(&20));
        assert_eq!(deque.back(), Some(&10));
    }

    #[test]
    fn test_push_back_and_front_back_access() {
        let mut deque = Deque::new();

        deque.push_back(5);
        assert_eq!(deque.len(), 1);
        assert_eq!(deque.front(), Some(&5));
        assert_eq!(deque.back(), Some(&5));

        deque.push_back(15);
        assert_eq!(deque.len(), 2);
        assert_eq!(deque.front(), Some(&5));
        assert_eq!(deque.back(), Some(&15));
    }

    #[test]
    fn test_pop_front() {
        let mut deque = Deque::new();
        assert_eq!(deque.pop_front(), None);

        deque.push_back(1);
        deque.push_back(2);
        deque.push_back(3);

        assert_eq!(deque.pop_front(), Some(1));
        assert_eq!(deque.len(), 2);
        assert_eq!(deque.front(), Some(&2));
        assert_eq!(deque.back(), Some(&3));

        assert_eq!(deque.pop_front(), Some(2));
        assert_eq!(deque.pop_front(), Some(3));
        assert!(deque.is_empty());
        assert_eq!(deque.pop_front(), None);
    }

    #[test]
    fn test_pop_back() {
        let mut deque = Deque::new();
        assert_eq!(deque.pop_back(), None);

        deque.push_front(10);
        deque.push_front(20);
        deque.push_front(30);

        assert_eq!(deque.pop_back(), Some(10));
        assert_eq!(deque.len(), 2);
        assert_eq!(deque.front(), Some(&30));
        assert_eq!(deque.back(), Some(&20));

        assert_eq!(deque.pop_back(), Some(20));
        assert_eq!(deque.pop_back(), Some(30));
        assert!(deque.is_empty());
        assert_eq!(deque.pop_back(), None);
    }

    #[test]
    fn test_clear_method() {
        let mut deque = Deque::new();
        deque.push_front(100);
        deque.push_back(200);
        deque.push_front(300);
        assert_eq!(deque.len(), 3);

        deque.clear();

        assert!(deque.is_empty());
        assert_eq!(deque.front(), None);
        assert_eq!(deque.back(), None);
    }

    #[test]
    fn test_mixed_operations() {
        let mut deque = Deque::new();
        deque.push_front(1);
        deque.push_back(2);
        deque.push_front(3);
        deque.push_back(4);

        assert_eq!(deque.len(), 4);
        assert_eq!(deque.front(), Some(&3));
        assert_eq!(deque.back(), Some(&4));

        assert_eq!(deque.pop_front(), Some(3));

        assert_eq!(deque.pop_back(), Some(4));
        assert_eq!(deque.front(), Some(&1));
        assert_eq!(deque.back(), Some(&2));
        assert_eq!(deque.len(), 2);
    }
}
