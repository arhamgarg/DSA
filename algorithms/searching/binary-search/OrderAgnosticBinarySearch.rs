fn main() {
    let arr: Vec<i32> = vec![1, 2, 4, 5, 7, 2, 7];
    let target: i32 = 7;
    let result: i32 = order_agnostic_binary_search(&arr, target);
    println!("Target found at index: {}", result);
}

fn order_agnostic_binary_search(arr: &[i32], target: i32) -> i32 {
    if arr.len() == 0 {
        return -1;
    }
    let mut start: i32 = 0;
    let mut end: i32 = arr.len() as i32 - 1;
    let is_ascending: bool = arr[start as usize] < arr[end as usize];
    while start <= end {
        let mid: i32 = start + (end - start) / 2;
        if arr[mid as usize] == target {
            return mid;
        }
        if is_ascending {
            if target < arr[mid as usize] {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            if target > arr[mid as usize] {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    -1
}
