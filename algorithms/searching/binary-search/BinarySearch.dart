class Searching {
  static binarySearch(List<int> arr, int target) {
    int low = 0;
    int high = arr.length;
    int mid;

    while (low <= high) {
      double half = ((high - low) / 2);
      mid = low + half.toInt();

      if (arr[mid] == target) {
        return mid;
      } else if (arr[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return -1;
  }
}
