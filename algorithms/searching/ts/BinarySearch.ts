function binarySearch(array: number[], target: number): number {
  let low: number = 0;
  let high: number = array.length - 1;
  let mid: number;

  while (high >= low) {
    mid = low + Math.floor((high - low) / 2);

    if (array[mid] == target) return mid;

    if (array[mid] > target) high = mid - 1;
    else low = mid + 1;
  }

  return -1;
}

export { binarySearch };
