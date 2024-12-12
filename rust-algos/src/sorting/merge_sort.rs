fn merge(arr: &mut Vec<i32>, left: usize, mid: usize, right: usize) {
    let n1: usize = mid - left + 1;
    let n2: usize = right - mid;

    let mut l: Vec<i32> = vec![0; n1];
    let mut r: Vec<i32> = vec![0; n2];

    for i in 0..n1 {
        l[i] = arr[left + i];
    }

    for j in 0..n2 {
        r[j] = arr[mid + 1 + j];
    }

    let mut i: usize = 0;
    let mut j: usize = 0;
    let mut k: usize = left;

    while i < n1 && j < n2 {
        if l[i] <= r[j] {
            arr[k] = l[i];
            i += 1;
        } else {
            arr[k] = r[j];
            j += 1;
        }
        k += 1;
    }

    while i < n1 {
        arr[k] = l[i];
        i += 1;
        k += 1;
    }

    while j < n2 {
        arr[k] = r[j];
        j += 1;
        k += 1;
    }
}

pub fn merge_sort(arr: &mut Vec<i32>, left: usize, right: usize) {
    if left < right {
        let mid: usize = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
