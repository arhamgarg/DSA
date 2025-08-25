public class OrderAgnosticBinarySearch {
  public static int orderAgnosticBinarySearch(int[] arr, int target) {
    if (arr == null || arr.length == 0)
      return -1;
    int low = 0, high = arr.length - 1;
    boolean ascending = arr[low] < arr[high];

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] == target)
        return mid;

      if (ascending) {
        if (target < arr[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (target > arr[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
    }
    return -1;
  }
}
