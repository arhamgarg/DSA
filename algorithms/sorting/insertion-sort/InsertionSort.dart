class Sorting {
  static List<int> InsertionSort(List<int> unsortedList) {
    int n = unsortedList.length;
    int j, key;

    for (int i = 1; i < n; i++) {
      key = unsortedList[i];
      j = i - 1;

      while (j >= 0 && unsortedList[j] > key) {
        unsortedList[j + 1] = unsortedList[j];
        j--;
      }

      unsortedList[j + 1] = key;
    }

    return unsortedList;
  }
}
