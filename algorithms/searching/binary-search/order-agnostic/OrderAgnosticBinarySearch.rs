fn orderAgnosticBinarySearch(arr: &[i32], target: i32) -> i32 {
    if arr.len() == 0 {
        return -1;
    }
    let mut start: i32 = 0;
    let mut end: i32 = arr.len() as i32 - 1;
    let isAscending: bool = arr[start as usize] < arr[end as usize];
    while start <= end {
        let mid: i32 = start + (end - start) / 2;
        if arr[mid as usize] == target {
            return mid;
        }
        if isAscending {
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
    return -1;
}
