use crate::utils::read_and_parse_data_to_int;

const MAX_SIZE: usize = 10;

pub struct Queue {
    data: [i32; MAX_SIZE],
    front: i32,
    rear: i32,
}

impl Queue {
    fn new() -> Queue {
        Queue {
            data: [0; MAX_SIZE],
            front: -1,
            rear: -1,
        }
    }

    fn enqueue(&mut self, item: i32) {
        let usize_rear: usize = usize::try_from(self.rear).unwrap();

        if usize_rear > MAX_SIZE {
            return println!("Queue limit reached!");
        }

        if self.front == -1 {
            self.front = 0;
        }

        self.rear += 1;
        self.data[usize_rear] = item;

        println!("Inserted!");
    }

    fn dequeue(&mut self) {
        if self.front == self.rear {
            return println!("No data to pop!");
        }

        let usize_top: usize = usize::try_from(self.front).unwrap();

        self.data[usize_top] = 0;
        self.front += 1;

        println!("Removed!");
    }

    fn display(&self) {
        let usize_front: usize = usize::try_from(self.front).unwrap();
        let usize_rear: usize = usize::try_from(self.rear).unwrap();

        println!("Data => {:?}", &self.data[usize_front..usize_rear]);
    }

    pub fn run() {
        let mut stack_data: Queue = Self::new();

        loop {
            println!("\n-------------");
            println!("1: Enqueue");
            println!("2: Dequeue");
            println!("3: Display");
            println!("Other: Exit");
            println!("-------------\n");

            let is_continue: bool =
                read_and_parse_data_to_int("Enter choice: ", |parsed_choice: i32| {
                    match parsed_choice {
                        1 => read_and_parse_data_to_int("Enter item: ", |parsed_item: i32| {
                            stack_data.enqueue(parsed_item);
                            true
                        }),
                        2 => {
                            stack_data.dequeue();
                            true
                        }
                        3 => {
                            stack_data.display();
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
