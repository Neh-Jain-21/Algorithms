pub struct LinkedList {
    data: String,
    next: Option<Box<LinkedList>>,
}

impl LinkedList {
    fn new(data: String) -> LinkedList {
        LinkedList { data, next: None }
    }

    fn traverse(&self) {
        let mut current: &LinkedList = self;

        loop {
            match &current.next {
                Some(next) => {
                    println!("{}", current.data);

                    current = &next;
                }
                None => break,
            }
        }
    }

    fn insert_at_end(&mut self, data: String) {
        let mut current: &mut LinkedList = self;
        let new_node: Option<Box<LinkedList>> = Some(Box::new(LinkedList {
            data: data.to_string(),
            next: None,
        }));

        loop {
            match current.next {
                Some(next) => {
                    current = next;
                }
                None => {
                    current.next = new_node;
                    break;
                }
            }
        }
    }

    pub fn run() {
        let mut list = LinkedList::new("10".to_owned());

        list.insert_at_end("20".to_owned());
    }
}
