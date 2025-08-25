class Searching {
  public static binarySearch(arr: number[], target: number): number {
    let low: number = 0;
    let high: number = arr.length - 1;
    let mid: number;

    while (high >= low) {
      mid = low + Math.floor((high - low) / 2);

      if (arr[mid] == target) return mid;
      else if (arr[mid] > target) high = mid - 1;
      else low = mid + 1;
    }

    return -1;
  }
}

export { Searching };
