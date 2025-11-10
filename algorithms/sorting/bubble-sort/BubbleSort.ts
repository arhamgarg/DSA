class Sorting {
	public BubbleSort(unsortedArray: number[]): number[] {
		let swapped: boolean;
		const length: number = unsortedArray.length;

		for (let i: number = 0; i < length; i++) {
			swapped = false;

			for (let j: number = 0; j < length; j++) {
				if (unsortedArray[j] > unsortedArray[j + 1]) {
					const temp: number = unsortedArray[j];
					unsortedArray[j] = unsortedArray[j + 1];
					unsortedArray[j + 1] = temp;
					swapped = true;
				}

				if (!swapped) break;
			}
		}

		return unsortedArray;
	}
}

export { Sorting };
