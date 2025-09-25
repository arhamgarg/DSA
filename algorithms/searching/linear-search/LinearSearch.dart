class Searching {
  static int linearSearch(List<int> array, int target) {
    int n = array.length;

    for (int i = 0; i < n; i++) {
      if (array[i] == target) {
        return i;
      }
    }

    return -1;
  }
}
