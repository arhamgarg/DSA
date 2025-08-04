void merge(int left[], int leftsize, int right[], int rightsize, int arr[]) {
  int i = 0, j = 0, k = 0;

  while (i < leftsize && j < rightsize) {
    if (left[i] <= right[j]) {
      arr[k++] = left[i++];
    } else {
      arr[k++] = right[j++];
    }
  }

  while (i < leftsize) {
    arr[k++] = left[i++];
  }

  while (j < rightsize) {
    arr[k++] = right[j++];
  }
}

void mergeSort(int arr[], int size) {
  if (size <= 1)
    return;

  int mid = size / 2;
  int left[mid], right[size - mid];

  for (int i = 0; i < mid; i++)
    left[i] = arr[i];

  for (int i = mid; i < size; i++)
    right[i - mid] = arr[i];

  mergeSort(left, mid);
  mergeSort(right, size - mid);
  merge(left, mid, right, size - mid, arr);
}
