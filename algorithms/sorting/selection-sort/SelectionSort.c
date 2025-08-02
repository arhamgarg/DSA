void selectionSort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int min_index = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}
