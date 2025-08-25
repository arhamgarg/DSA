import 'dart:math';

class Sorting {
  static List<int> QuickSort(List<int> unsortedList, int low, int high) {
    if (low < high) {
      int pivotIndex = Sorting._Partition(unsortedList, low, high);
      Sorting.QuickSort(unsortedList, low, pivotIndex - 1);
      Sorting.QuickSort(unsortedList, pivotIndex + 1, high);
    }

    return unsortedList;
  }

  static int _Partition(List<int> unsortedList, int low, int high) {
    int pivot = unsortedList[high];
    int i = low - 1;
    int temp;

    for (int j = low; j < high; j++) {
      if (unsortedList[j] < pivot) {
        i++;
        temp = unsortedList[i];
        unsortedList[i] = unsortedList[j];
        unsortedList[j] = temp;
      }
    }

    temp = unsortedList[i + 1];
    unsortedList[i + 1] = unsortedList[high];
    unsortedList[high] = temp;
    return i + 1;
  }
}
