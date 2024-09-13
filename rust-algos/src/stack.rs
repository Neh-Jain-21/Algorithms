use crate::utils::read_and_parse_data_to_int;

const MAX_SIZE: usize = 10;

pub struct Stack {
    data: [i32; MAX_SIZE],
    top: i32,
}

impl Stack {
    fn new() -> Stack {
        Stack {
            data: [0; MAX_SIZE],
            top: -1,
        }
    }

    fn push(&mut self, item: i32) {
        if self.top == (MAX_SIZE - 1).try_into().unwrap() {
            return println!("Max size reached");
        }

        let usize_top: usize = usize::try_from(self.top + 1).unwrap();

        self.data[usize_top] = item;
        self.top += 1;

        println!("Inserted!");
    }

    fn pop(&mut self) {
        if self.top == -1 {
            return println!("No data to pop!");
        }

        let usize_top: usize = usize::try_from(self.top + 1).unwrap();

        self.data[usize_top] = 0;
        self.top -= 1;

        println!("Removed!");
    }

    fn peep(&self, index: i32) {
        if index < 0 || index > (self.top) {
            return println!("Invalid index");
        }

        let usize_index: usize = usize::try_from(index).unwrap();

        println!("{} at index {}", self.data[usize_index], index);
    }

    fn change(&mut self, item: i32, index: i32) {
        if index < 0 || index > (self.top + 1) {
            return println!("Invalid index");
        }

        let usize_index: usize = usize::try_from(index).unwrap();

        self.data[usize_index] = item;

        println!("Changed!");
    }

    fn display(&self) {
        println!("Top => {}", self.top);

        let usize_top: usize = usize::try_from(self.top + 1).unwrap();

        println!("Data => {:?}", &self.data[0..usize_top]);
    }

    pub fn run() {
        let mut stack_data: Stack = Self::new();

        loop {
            println!("\n-------------");
            println!("1: Push");
            println!("2: Pop");
            println!("3: Peep");
            println!("4: Change");
            println!("5: Display");
            println!("Other: Exit");
            println!("-------------\n");

            let is_continue: bool =
                read_and_parse_data_to_int("Enter choice: ", |parsed_choice: i32| {
                    match parsed_choice {
                        1 => read_and_parse_data_to_int("Enter item: ", |parsed_item: i32| {
                            stack_data.push(parsed_item);
                            true
                        }),
                        2 => {
                            stack_data.pop();
                            true
                        }
                        3 => read_and_parse_data_to_int("Enter index: ", |parsed_index: i32| {
                            stack_data.peep(parsed_index);
                            true
                        }),
                        4 => read_and_parse_data_to_int("Enter index: ", |parsed_index: i32| {
                            read_and_parse_data_to_int("Enter item: ", |parsed_item: i32| {
                                stack_data.change(parsed_item, parsed_index);
                                true
                            })
                        }),
                        5 => {
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
