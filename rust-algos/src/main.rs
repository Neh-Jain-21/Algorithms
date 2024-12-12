use rust_algos::sorting::merge_sort::merge_sort;

fn main() {
    let mut data: Vec<i32> = vec![12, 11, 13, 5, 6, 7];

    let total_length = data.len();

    merge_sort(&mut data, 0, total_length - 1);

    println!("{:?}", data);
}
