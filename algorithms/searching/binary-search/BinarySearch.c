int BinarySearch(int[] sortedArray, int target) {
    int low = 0;
    int high = sizeof(sortedArray) / sizeof(sortedArray[0]);

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sortedArray[mid] == target) {
            return mid;
        } else if (sortedArray[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1
}