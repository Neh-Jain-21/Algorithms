const MAX_SIZE: usize = 10;

pub struct Stack {
    data: [i32; MAX_SIZE],
    top: i32,
}

impl Stack {
    pub fn new() -> Stack {
        Stack {
            data: [0; MAX_SIZE],
            top: -1,
        }
    }

    pub fn push(&mut self, item: i32) {
        if self.top == (MAX_SIZE - 1).try_into().unwrap() {
            return println!("Max size reached");
        }

        let usize_top: usize = usize::try_from(self.top + 1).unwrap();

        self.data[usize_top] = item;
        self.top += 1;
    }

    pub fn pop() {}

    pub fn peep() {}

    pub fn change() {}

    pub fn display(&self) {
        if self.top == -1 {
            return println!("No Data");
        }

        println!("Top is at: {}", self.top);

        for item in (0..(self.top + 1)).rev() {
            let usize_item: usize = usize::try_from(item).unwrap();

            println!("{}", self.data[usize_item]);
        }
    }
}
