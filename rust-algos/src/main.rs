use rust_algos::sorting::{
    bubble_sort::{bubble_sort, MAX_SIZE},
    merge_sort::{self, merge_sort},
};

fn main() {
    let mut data: [i32; MAX_SIZE] = [0, 10, 40, 30, 20, 80, 70, 60, 100, 50];

    bubble_sort(&mut data);
    merge_sort(&mut data);

    println!("{:?}", data);
}
