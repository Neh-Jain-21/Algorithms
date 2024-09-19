use crate::utils::read_and_parse_data_to_int;

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

    fn insert_at_beginning(&mut self, data: String) {
        let new_node: Box<ListNode> = Box::new(ListNode {
            data,
            next: self.head.take(),
        });

        self.head = Some(new_node);

        println!("Inserted!");
    }

    fn remove_from_beginning(&mut self) -> Option<String> {
        self.head.take().map(|node: Box<ListNode>| {
            self.head = node.next;
            node.data
        })
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
                }
                None => {
                    println!("Inserted!");

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
        let mut list: LinkedList = LinkedList::new();

        loop {
            println!("\n-------------");
            println!("1: Insert at beginning");
            println!("2: Insert at end");
            println!("3: Remove from beginning");
            println!("4: Display");
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
