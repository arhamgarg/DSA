function linearSearch(array: number[], n: number, target: number): number {
  for (let i: number = 0; i < n; i++) {
    if (array[i] == target) {
      return i;
    }
  }

  return -1;
}

export { linearSearch };
