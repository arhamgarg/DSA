class Sorting {
  static List<int> SelectionSort(List<int> unsortedList) {
    int n = unsortedList.length;
    int min, temp;

    for (int i = 0; i < n; i++) {
      min = i;

      for (int j = i; j < n; j++) {
        if (unsortedList[j] < unsortedList[min]) {
          min = j;
        }
      }

      temp = unsortedList[min];
      unsortedList[min] = unsortedList[i];
      unsortedList[i] = temp;
    }

    return unsortedList;
  }
}
