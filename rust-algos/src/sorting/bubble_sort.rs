pub const MAX_BUBBLE_SORT_SIZE: usize = 10;

pub fn bubble_sort<T>(data: &mut [T; MAX_BUBBLE_SORT_SIZE])
where
    T: Ord,
{
    for i in 1..(data.len() - 1) {
        for j in 0..(data.len() - i) {
            if data[j] > data[j + 1] {
                data.swap(j, j + 1);
            }
        }
    }
}
