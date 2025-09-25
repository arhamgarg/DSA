class Searching {
  public static linearSearch(arr: number[], n: number, target: number): number {
    for (let i: number = 0; i < n; i++) {
      if (arr[i] == target) {
        return i;
      }
    }

    return -1;
  }
}
