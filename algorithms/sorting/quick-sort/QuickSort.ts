class Sorting {
  private static partition(array: number[], low: number, high: number): number {
    let pivot: number = array[high];
    let i: number = low - 1;
    let temp: number;

    for (let j: number = low; j < high; j++) {
      if (array[j] < pivot) {
        i++;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
  }

  public static QuickSort(
    unsortedArray: number[],
    low: number,
    high: number,
  ): number[] {
    if (low < high) {
      let pivotIndex: number = this.partition(unsortedArray, low, high);
      this.QuickSort(unsortedArray, low, pivotIndex - 1);
      this.QuickSort(unsortedArray, pivotIndex + 1, high);
    }

    return unsortedArray;
  }
}
