pub const MAX_MERGE_SORT_SIZE: usize = 6;

fn merge(arr: &mut [i32; MAX_MERGE_SORT_SIZE], left: i32, mid: i32, right: i32) {
    let n1: i32 = mid - left + 1;
    let n2: i32 = right - mid;

    let mut l: [i32; MAX_MERGE_SORT_SIZE] = [0, 0, 0, 0, 0, 0];
    let mut r: [i32; MAX_MERGE_SORT_SIZE] = [0, 0, 0, 0, 0, 0];

    for i in 0..(n1 - 1) {
        l[i as usize] = arr[(left + i) as usize];
    }

    for j in 0..(n2 - 1) {
        r[j as usize] = arr[(mid + 1 + j) as usize];
    }

    let mut i: i32 = 0;
    let mut j: i32 = 0;
    let mut k: i32 = left;

    while i < n1 && j < n2 {
        if l[i as usize] <= r[j as usize] {
            arr[k as usize] = l[i as usize];
            i += 1;
        } else {
            arr[k as usize] = r[j as usize];
            j += 1;
        }

        k += 1;
    }

    while i < n1 {
        arr[k as usize] = l[i as usize];
        i += 1;
        k += 1;
    }

    while j < n2 {
        arr[k as usize] = r[j as usize];
        j += 1;
        k += 1;
    }
}

pub fn merge_sort(arr: &mut [i32; MAX_MERGE_SORT_SIZE], left: i32, right: i32) {
    if left >= right {
        return;
    }

    let mid: i32 = (((left + (right - left)) / 2) as f32).floor() as i32;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);

    println!("{:?}", arr);
}
