use std::fmt::Debug;

pub const MAX_MERGE_SORT_SIZE: usize = 4;

fn divide_and_conquer<T>(data: &mut [T; MAX_MERGE_SORT_SIZE], lower_bound: i32, upper_bound: i32)
where
    T: Ord + Debug,
{
    println!("{:?}", data);
    println!("{:?}", lower_bound);
    println!("{:?}", upper_bound);
}

pub fn merge_sort<T>(data: &mut [T; MAX_MERGE_SORT_SIZE])
where
    T: Ord + Debug,
{
    let total_length: i32 = data.len().try_into().unwrap();
    let mid: i32 = ((total_length - 1) / 2).try_into().unwrap();

    divide_and_conquer(data, 0, mid);
    divide_and_conquer(data, mid + 1, total_length - 1);
}
