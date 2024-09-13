use std::io::{self, Write};

pub fn read_and_parse_data_to_int<F>(message: &str, mut closure: F) -> bool
where
    F: FnMut(i32) -> bool,
{
    print!("{}", message);
    io::stdout().flush().unwrap();

    let mut item: String = String::new();

    io::stdin().read_line(&mut item).expect("Read Failed!");
    let parsed_item: Result<i32, _> = item.trim().parse();

    match parsed_item {
        Ok(item) => closure(item),
        Err(_) => {
            println!("Cannot parse your input");
            false
        }
    }
}
