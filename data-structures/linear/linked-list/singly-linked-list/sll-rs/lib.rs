#![allow(dead_code)]

struct Node<T> {
    value: T,
    next: Option<Box<Node<T>>>,
}

struct LinkedList<T> {
    head: Option<Box<Node<T>>>,
    size: usize,
}

impl<T> LinkedList<T> {
    fn new() -> Self {
        LinkedList {
            head: None,
            size: 0,
        }
    }

    fn is_empty(&self) -> bool {
        self.head.is_none()
    }

    fn len(&self) -> usize {
        return self.size;
    }

    fn head(&self) -> Option<&T> {
        // self.head is of the type -- Option<Box<Node<T>>>
        // .as_ref() converts it to Option<&Box<Node<T>>>
        // .map(|node| &node.value) extracts a reference to the value inside
        self.head.as_ref().map(|node| &node.value)

        // -- For clarity, map() does the following but conscisely:
        // match self.head.as_ref() {
        //     Some(node) => Some(&node.value),
        //     None => None,
        // }
    }

    fn insert_at_head(&mut self, value: T) {
        let new_node = Box::new(Node {
            value,
            next: self.head.take(), // takes ownership; self.head = None
        });
        self.head = Some(new_node); // new head allocated in memory
        self.size += 1;
    }

    fn insert_at_tail(&mut self, value: T) {
        let new_node = Box::new(Node { value, next: None });

        // Taking a mutable reference to the head, we recursively check if it
        // resolves to Some() or None as it is an Option<> type. When it becomes
        // None, then we deference the memory location and store a box pointer
        // in it which points to a location in the heap memory where the new
        // element is stored.
        //
        // Remember: Our LinkedList nodes are Box<Node<T>> and not
        // Node<T>. Unlike other languages which allow this, Rust types must
        // be defined memory and a Node<T> does not have a defined memory as
        // it references itself as a member and leads to infinite memory
        let mut cur = &mut self.head;
        while let Some(node) = cur {
            cur = &mut node.next;
        }
        *cur = Some(new_node); // cur is the memory address of last node in the list

        self.size += 1;
    }

    fn pop_at_head(&mut self) -> Option<T> {
        self.head.take().map(|node| {
            self.head = node.next;
            self.size -= 1;
            node.value
        })
    }

    fn pop_at_tail(&mut self) -> Option<T> {
        match self.head.as_mut() {
            None => None, // LL is empty
            Some(node) if node.next.is_none() => {
                // There is only one element in the list so we pop it out

                // take() method takes the ownership of the head
                // Now, self.head == None
                // Option<T> needs to be unwrapped into <T>, otherwise we can't
                // access it's members
                let head = self.head.take().unwrap();
                self.size -= 1;
                Some(head.value)
            }
            Some(_) => {
                // More than one element is left, so we find second last node
                // by check if Node.next.next != null
                let mut current = self.head.as_mut().unwrap();
                while current.next.as_ref().unwrap().next.is_some() {
                    current = current.next.as_mut().unwrap();
                }

                // current has the reference of the second last node
                // Using current, we are taking the ownership of the last node
                // which is returning Option<T> that is unwrapped and it's value
                // is returned
                let last_node = current.next.take().unwrap();
                self.size -= 1;
                Some(last_node.value)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_new_list_is_empty() {
        let mut ll: LinkedList<i32> = LinkedList::new();
        assert!(ll.is_empty());
        assert_eq!(ll.len(), 0);
        assert_eq!(ll.pop_at_head(), None);
        assert_eq!(ll.pop_at_tail(), None);
    }

    #[test]
    fn test_push_front_increases_size() {
        let mut ll: LinkedList<i32> = LinkedList::new();

        ll.insert_at_head(10);
        assert!(!ll.is_empty());
        assert_eq!(ll.len(), 1);

        ll.insert_at_head(20);
        assert!(!ll.is_empty());
        assert_eq!(ll.len(), 2);
    }

    #[test]
    fn test_push_back_increases_size() {
        let mut ll: LinkedList<i32> = LinkedList::new();

        ll.insert_at_tail(10);
        assert!(!ll.is_empty());
        assert_eq!(ll.len(), 1);

        ll.insert_at_tail(20);
        assert!(!ll.is_empty());
        assert_eq!(ll.len(), 2);
    }

    #[test]
    fn test_pop_front_returns_first_element() {
        let mut ll: LinkedList<i32> = LinkedList::new();

        ll.insert_at_head(20);
        ll.insert_at_head(30);
        ll.insert_at_head(40);
        assert_eq!(ll.pop_at_head(), Some(40));
        assert_eq!(ll.len(), 2);
        assert_eq!(ll.head(), Some(&30));
    }

    #[test]
    fn test_pop_front_on_empty_list_returns_none() {
        let mut ll: LinkedList<i32> = LinkedList::new();
        assert_eq!(ll.pop_at_head(), None);
    }

    #[test]
    fn test_pop_back_returns_last_element() {
        let mut ll: LinkedList<i32> = LinkedList::new();

        ll.insert_at_head(20);
        ll.insert_at_head(30);
        ll.insert_at_head(40);
        assert_eq!(ll.pop_at_tail(), Some(20));
        assert_eq!(ll.pop_at_tail(), Some(30));
        assert_eq!(ll.pop_at_tail(), Some(40));
        assert_eq!(ll.pop_at_tail(), None);
    }
}
