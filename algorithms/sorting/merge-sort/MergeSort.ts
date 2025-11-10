class Sorting {
	private merge(
		array: number[],
		first: number,
		mid: number,
		last: number,
	): void {
		const newArray: Array<number> = [];
		let i: number = first;
		let j: number = mid + 1;
		const len: number = array.length;

		while (i <= mid && j <= last) {
			if (array[i] < array[j]) {
				newArray.push(array[i]);
				i++;
			} else {
				newArray.push(array[j]);
				j++;
			}
		}

		while (i <= mid) {
			newArray.push(array[i]);
			i++;
		}

		while (j <= last) {
			newArray.push(array[j]);
			j++;
		}

		for (let idx: number = 0; idx < len; idx++) {
			array[idx + first] = newArray[idx];
		}
	}

	public MergeSort(array: number[], first: number, last: number): number[] {
		if (first < last) {
			const mid: number = first + (last - first) / 2;

			this.MergeSort(array, first, mid);
			this.MergeSort(array, mid + 1, last);

			this.merge(array, first, mid, last);
		}

		return array;
	}
}

export { Sorting };
