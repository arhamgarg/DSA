class Sorting {
  static _merge(List<int> lst, int first, int mid, int last) {
    List<int> newLst = [];
    int i = first;
    int j = mid + 1;
    int len = lst.length;
    int listIdx = 0;

    while (i <= mid && j <= last) {
      if (lst[i] < lst[j]) {
        newLst.insert(listIdx, lst[i]);
        i++;
      } else {
        newLst.insert(listIdx, lst[j]);
        j++;
      }

      listIdx++;
    }

    while (i <= mid) {
      newLst.insert(listIdx, lst[i]);
      i++;
      listIdx++;
    }

    while (j <= last) {
      newLst.insert(listIdx, lst[j]);
      j++;
      listIdx++;
    }

    for (int index = 0; index < len; index++) {
      lst[index + first] = newLst[index];
    }
  }

  static List<int> MergeSort(List<int> unsortedList, int first, int last) {
    if (first < last) {
      double half = (last - first) / 2;
      int mid = first + half.toInt();

      Sorting.MergeSort(unsortedList, first, mid);
      Sorting.MergeSort(unsortedList, mid + 1, last);

      Sorting._merge(unsortedList, first, mid, last);
    }

    return unsortedList;
  }
}
