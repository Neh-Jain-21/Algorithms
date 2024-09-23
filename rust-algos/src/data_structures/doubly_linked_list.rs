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

impl Drop for DoublyLinkedList {
    fn drop(&mut self) {
        while self.remove_from_beginning().is_some() {}
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
                head.borrow_mut().prev = Some(new_head.clone()); // +1
                new_head.borrow_mut().next = Some(head); // +1

                self.head = Some(new_head); // +1 -1
            }
            None => {
                self.head = Some(new_head.clone());
                self.tail = Some(new_head);
            }
        }
    }

    fn remove_from_beginning(&mut self) -> Option<String> {
        self.head.take().map(|head: Rc<RefCell<ListNode>>| {
            match head.borrow_mut().next.take() {
                Some(new_head) => {
                    new_head.borrow_mut().prev.take();
                    self.head = Some(new_head);
                }
                None => {
                    self.tail.take();
                }
            };

            Rc::try_unwrap(head).ok().unwrap().into_inner().data
        })
    }

    fn insert_at_end(&mut self, data: String) {
        let new_tail: Rc<RefCell<ListNode>> = ListNode::new(data);

        match self.tail.take() {
            Some(tail) => {
                tail.borrow_mut().next = Some(new_tail.clone());
                new_tail.borrow_mut().prev = Some(tail);

                self.tail = Some(new_tail);
            }
            None => {
                self.head = Some(new_tail.clone());
                self.tail = Some(new_tail);
            }
        }
    }

    fn remove_from_end(&mut self) -> Option<String> {
        self.tail.take().map(|tail: Rc<RefCell<ListNode>>| {
            match tail.borrow_mut().prev.take() {
                Some(new_tail) => {
                    new_tail.borrow_mut().next.take();
                    self.tail = Some(new_tail);
                }
                None => {
                    self.head.take();
                }
            };

            Rc::try_unwrap(tail).ok().unwrap().into_inner().data
        })
    }

    fn traverse(&self) {}

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
