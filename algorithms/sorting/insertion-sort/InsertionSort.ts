class Sorting {
	public InsertionSort(unsortedArray: number[]): number[] {
		const n: number = unsortedArray.length;
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

export { Sorting };
