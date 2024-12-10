pub const MAX_MERGE_SORT_SIZE: usize = 4;

fn sort(data: &mut [i32; MAX_MERGE_SORT_SIZE], lower_bound: i32, upper_bound: i32, mid: i32) {
    let mut i: i32 = lower_bound;
    let mut j: i32 = mid + 1;
    let mut k: i32 = lower_bound;
    let mut temp: [i32; MAX_MERGE_SORT_SIZE] = [0, 0, 0, 0];

    while i <= mid && j <= upper_bound {
        if data[i as usize] < data[j as usize] {
            temp[k as usize] = data[i as usize];
            i += 1;
        } else {
            temp[k as usize] = data[j as usize];
            j += 1;
        }

        k += 1;
    }

    while i <= mid {
        temp[k as usize] = data[i as usize];
        i += 1;
        k += 1;
    }

    while j <= upper_bound {
        temp[k as usize] = data[j as usize];
        j += 1;
        k += 1;
    }

    for i in lower_bound..upper_bound + 1 {
        data[i as usize] = temp[i as usize];
    }
}

pub fn merge_sort(data: &mut [i32; MAX_MERGE_SORT_SIZE], lb: Option<i32>, up: Option<i32>) {
    let total_length: i32 = data.len().try_into().unwrap();

    let lower_bound: i32 = lb.unwrap_or(0);
    let upper_bound: i32 = up.unwrap_or(total_length);

    if lower_bound < upper_bound {
        let mid: i32 = (lower_bound + upper_bound) / 2;

        merge_sort(data, Some(lower_bound), Some(mid));
        merge_sort(data, Some(mid + 1), Some(upper_bound));
        sort(data, lower_bound, upper_bound - 1, mid);
    }
}
