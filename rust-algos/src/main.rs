use rust_algos::sorting::merge_sort::{merge_sort, MAX_MERGE_SORT_SIZE};

fn main() {
    let mut data: [i32; MAX_MERGE_SORT_SIZE] = [12, 11, 13, 5, 6, 7];

    let total_length: i32 = data.len().try_into().unwrap();

    merge_sort(&mut data, 0, total_length - 1);

    println!("{:?}", data);
}
