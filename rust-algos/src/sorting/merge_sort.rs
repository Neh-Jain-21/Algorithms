pub const MAX_MERGE_SORT_SIZE: usize = 4;

fn divide_and_conquer(data: &mut [i32; MAX_MERGE_SORT_SIZE], lower_bound: i32, upper_bound: i32) {
    let sliced_data: &mut [i32] = &mut data[lower_bound as usize..(upper_bound + 1) as usize];

    if sliced_data.len() == 2 && sliced_data[0] > sliced_data[1] {
        sliced_data.swap(0, 1);
    }
}

pub fn merge_sort(data: &mut [i32; MAX_MERGE_SORT_SIZE]) {
    let total_length: i32 = data.len().try_into().unwrap();
    let mid: i32 = ((total_length - 1) / 2).try_into().unwrap();

    divide_and_conquer(data, 0, mid);
    divide_and_conquer(data, mid + 1, total_length - 1);

    println!("{:?}", data);
}
