use rust_algos::stack::Stack;

fn main() {
    let mut stack_data = Stack::new();

    stack_data.push(12);

    stack_data.display();

    stack_data.push(13);

    stack_data.display();
}
