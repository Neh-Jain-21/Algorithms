use std::io;

use rust_algos::stack::Stack;

fn main() {
    let mut stack_data: Stack = Stack::new();

    loop {
        let mut choice = String::new();

        println!("Enter choice");

        io::stdin().read_line(&mut choice).expect("Read Failed!");

        println!("Your choice is {}", choice);

        match choice.as_str() {
            "1" => stack_data.push(10),
            &_ => break,
        };
    }
}
