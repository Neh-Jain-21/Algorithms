use std::io::{self, Write};

use rust_algos::stack::Stack;

fn main() {
    let mut stack_data: Stack = Stack::new();

    loop {
        let mut choice: String = String::new();
        let mut item: String = String::new();

        println!("1: Push");
        println!("2: Pop");
        println!("3: Peep");
        println!("4: Change");
        println!("5: Display");
        println!("Other: Exit\n");

        print!("Enter choice: ");
        io::stdout().flush().unwrap();

        io::stdin().read_line(&mut choice).expect("Read Failed!");

        match choice.trim() {
            "1" => {
                print!("Enter item: ");
                io::stdout().flush().unwrap();

                io::stdin().read_line(&mut item).expect("Read Failed!");
                let parsed_item: Result<i32, _> = item.trim().parse();

                match parsed_item {
                    Ok(item) => {
                        stack_data.push(item);
                        println!("Inserted!\n");
                    }
                    Err(_) => println!("Cannot parse your input"),
                };
            }
            "2" => todo!(),
            "3" => todo!(),
            "4" => todo!(),
            "5" => stack_data.display(),
            _other => {
                println!("Bye!!\n");
                break;
            }
        };
    }
}
