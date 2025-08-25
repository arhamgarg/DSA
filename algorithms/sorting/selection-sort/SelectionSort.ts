class Sorting {
  public static SelectionSort(unsortedArray: number[]): number[] {
    let n: number = unsortedArray.length;
    let min: number, temp: number;

    for (let i: number = 0; i < n; i++) {
      min = i;

      for (let j: number = i; j < n; j++) {
        if (unsortedArray[j] < unsortedArray[min]) {
          min = j;
        }
      }

      temp = unsortedArray[min];
      unsortedArray[min] = unsortedArray[i];
      unsortedArray[i] = temp;
    }

    return unsortedArray;
  }
}
