fn binary_search(arr: &[i32], target: i32) -> i32 {
    if arr.len() == 0 {
        return -1;
    }

    let mut start = 0;
    let mut end = arr.len() as i32 - 1;

    while start <= end {
        let mid = start + (end - start) / 2;
        if arr[mid as usize] == target {
            return mid;
        }
        if target < arr[mid as usize] {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}
