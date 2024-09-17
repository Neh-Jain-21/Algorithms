type NodePointer = Option<Box<ListNode>>;

struct ListNode {
    data: String,
    next: NodePointer,
}

pub struct LinkedList {
    head: NodePointer,
}

impl LinkedList {
    fn new() -> Self {
        Self { head: None }
    }

    fn traverse(&self) {
        let mut head: &Option<Box<ListNode>> = &self.head;

        loop {
            match head {
                Some(node) => {
                    println!("{}", node.data);

                    head = &node.next;
                }
                None => break,
            }
        }
    }

    fn insert_at_beginning(&mut self, data: String) {
        // let mut head: &Option<Box<ListNode>> = &self.head;

        let mut new_node: Box<ListNode> = Box::new(ListNode { data, next: None });

        if self.head.is_some() {
            unsafe {
                new_node.next = self.head;
            }

            self.head = Some(new_node);

            // self.head = Some(ptr);
        }
    }

    fn insert_at_end(&mut self, data: String) {
        let mut head: &mut Option<Box<ListNode>> = &mut self.head;
        let new_node: Option<Box<ListNode>> = Some(Box::new(ListNode { data, next: None }));

        loop {
            match head {
                Some(node) => {
                    head = &mut node.next;
                }
                None => {
                    *head = new_node;
                    println!("inserted {:?}", head.as_ref().unwrap().data);
                    break;
                }
            }
        }
    }

    pub fn run() {
        let mut list: LinkedList = LinkedList::new();

        list.insert_at_beginning("10".to_owned());

        list.traverse();
    }
}
