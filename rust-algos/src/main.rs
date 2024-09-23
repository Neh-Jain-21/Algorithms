use rust_algos::sorting::bubble_sort::{bubble_sort, MAX_SIZE};

fn main() {
    let mut data: [i32; MAX_SIZE] = [0, 10, 40, 30, 20, 80, 70, 60, 100, 50];

    bubble_sort(&mut data);

    println!("{:?}", data);
}
