use rust_algos::sorting::merge_sort::{merge_sort, MAX_MERGE_SORT_SIZE};

fn main() {
    let mut data: [i32; MAX_MERGE_SORT_SIZE] = [0, 10, 40, 30];

    merge_sort(&mut data);

    println!("{:?}", data);
}
