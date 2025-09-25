class Sorting {
  static List<int> BubbleSort(List<int> unsortedList) {
    bool swapped;
    int len = unsortedList.length;
    int temp;

    for (int i = 0; i < len; i++) {
      swapped = false;

      for (int j = 0; j < len; j++) {
        if (unsortedList[j] > unsortedList[j + 1]) {
          temp = unsortedList[j];
          unsortedList[j] = unsortedList[j + 1];
          unsortedList[j + 1] = temp;
          swapped = true;
        }
      }

      if (!swapped) {
        break;
      }
    }

    return unsortedList;
  }
}
