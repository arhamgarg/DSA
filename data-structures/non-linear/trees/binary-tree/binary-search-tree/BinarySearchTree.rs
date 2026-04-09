#[derive(Debug)]
pub struct Node<T: Ord> {
    val: T,
    left: Option<Box<Node<T>>>,
    right: Option<Box<Node<T>>>,
}

impl<T: Ord> Node<T> {
    pub fn new(val: T) -> Self {
        Node {
            val,
            left: None,
            right: None,
        }
    }

    pub fn insert(&mut self, val: T) {
        if val < self.val {
            match &mut self.left {
                Some(left) => left.insert(val),
                None => self.left = Some(Box::new(Node::new(val))),
            }
        } else if val > self.val {
            match &mut self.right {
                Some(right) => right.insert(val),
                None => self.right = Some(Box::new(Node::new(val))),
            }
        }
        // Equal values are ingored as there is no duplication seen in BST
    }

    // Rescursive checks on either sides
    pub fn contains(&self, val: T) -> bool {
        if val == self.val {
            true
        } else if val < self.val {
            self.left.as_ref().map_or(false, |left| left.contains(val))
        } else {
            self.right
                .as_ref()
                .map_or(false, |right| right.contains(val))
        }
    }
}

#[derive(Debug)]
pub struct BST<T: Ord> {
    root: Option<Box<Node<T>>>,
}

impl<T: Ord> BST<T> {
    pub fn new() -> Self {
        BST { root: None }
    }

    pub fn insert(&mut self, val: T) {
        match &mut self.root {
            Some(root) => root.insert(val),
            None => self.root = Some(Box::new(Node::new(val))),
        }
    }

    pub fn contains(&self, val: T) -> bool {
        self.root.as_ref().map_or(false, |root| root.contains(val))
    }
}

fn main() {
    let mut bst = BST::new();

    // Insert values
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    // Simpler test suite
    let tests = [7, 2, 10, 15];
    for &val in &tests {
        if bst.contains(val) {
            println!("BST contains {}", val);
        } else {
            println!("BST does not contain {}", val);
        }
    }

    // Print the BST structure (optional)
    println!("{:#?}", bst);
}
