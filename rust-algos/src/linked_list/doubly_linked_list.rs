use std::{cell::RefCell, rc::Rc};

use crate::utils::read_and_parse_data_to_int;

type NodePointer = Option<Rc<RefCell<ListNode>>>;

struct ListNode {
    data: String,
    prev: NodePointer,
    next: NodePointer,
}

pub struct DoublyLinkedList {
    head: NodePointer,
    tail: NodePointer,
}

impl ListNode {
    fn new(data: String) -> Rc<RefCell<ListNode>> {
        Rc::new(RefCell::new(ListNode {
            data,
            prev: None,
            next: None,
        }))
    }
}

impl DoublyLinkedList {
    fn new() -> Self {
        Self {
            head: None,
            tail: None,
        }
    }

    fn insert_at_beginning(&mut self, data: String) {
        let new_head: Rc<RefCell<ListNode>> = ListNode::new(data);

        match self.head.take() {
            Some(head) => {
                head.borrow_mut().prev = Some(new_head.clone());
                new_head.borrow_mut().next = Some(head);

                self.head = Some(new_head);
            }
            None => {
                self.head = Some(new_head.clone());
                self.tail = Some(new_head);
            }
        }
    }

    fn remove_from_beginning(&mut self) {
        self.head.take().map(|node: Box<ListNode>| {
            self.head = node.next;
            node.data
        });

        println!("Removed~");
    }

    fn insert_at_end(&mut self, data: String) {
        let mut head: &mut Option<Box<ListNode>> = &mut self.head;
        let new_node: Option<Box<ListNode>> = Some(Box::new(ListNode {
            data,
            prev: None,
            next: None,
        }));

        loop {
            match head {
                Some(node) => {
                    head = &mut node.next;
                }
                None => {
                    new_node.unwrap().prev = head;

                    *head = new_node;

                    println!("Inserted!");

                    break;
                }
            }
        }
    }

    fn remove_from_end(&mut self) {
        let mut head: &mut Option<Box<ListNode>> = &mut self.head;

        loop {
            match head {
                Some(node) => {
                    head = &mut node.next;

                    if head.as_ref().unwrap().next.is_none() {
                        *head = None;
                        println!("Removed!");
                    }
                }
                None => {
                    break;
                }
            }
        }
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

    pub fn run() {
        let mut list: DoublyLinkedList = DoublyLinkedList::new();

        loop {
            println!("\n-------------");
            println!("1: Insert at beginning");
            println!("2: Insert at end");
            println!("3: Remove from beginning");
            println!("4: Remove from end");
            println!("5: Display");
            println!("Other: Exit");
            println!("-------------\n");

            let is_continue: bool =
                read_and_parse_data_to_int("Enter choice: ", |parsed_choice: i32| {
                    match parsed_choice {
                        1 => read_and_parse_data_to_int("Enter item: ", |parsed_item: i32| {
                            list.insert_at_beginning(parsed_item.to_string());
                            true
                        }),
                        2 => read_and_parse_data_to_int("Enter item: ", |parsed_item: i32| {
                            list.insert_at_end(parsed_item.to_string());
                            true
                        }),
                        3 => {
                            list.remove_from_beginning();
                            true
                        }
                        4 => {
                            list.remove_from_end();
                            true
                        }
                        5 => {
                            list.traverse();
                            true
                        }
                        _other => {
                            println!("Bye!!\n");
                            false
                        }
                    }
                });

            if !is_continue {
                break;
            }
        }
    }
}
