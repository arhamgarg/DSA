class Searching {
  static BinarySearch(List<int> sortedList, int target) {
    int low = 0;
    int high = sortedList.length;

    while (low <= high) {
      double half = ((high - low) / 2);
      int mid = low + half.toInt();
      
      if (sortedList[mid] == target) {
        return mid;
      } else if (sortedList[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return -1;
  }
}