class Sorting {
  public static InsertionSort(unsortedArray: number[]): number[] {
    let n: number = unsortedArray.length;
    let j: number, key: number;

    for (let i = 1; i < n - 1; i++) {
      key = unsortedArray[i];
      j = i - 1;

      while (j >= 0 && unsortedArray[j] > key) {
        unsortedArray[j + 1] = unsortedArray[j];
        j--;
      }

      unsortedArray[j + 1] = key;
    }

    return unsortedArray;
  }
}
