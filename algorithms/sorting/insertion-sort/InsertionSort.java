public class InsertionSort {
  public static int[] insertionSort(int[] arr) {
    for (int i = 1; i < arr.length; i++) {
      boolean swapped = false;
      int current = arr[i];
      int j = i - 1;

      while (j >= 0 && arr[j] > current) {
        arr[j + 1] = arr[j];
        j--;
        swapped = true;
      }

      arr[j + 1] = current;

      if (!swapped) {
        break;
      }
    }

    return arr;
  }
}
