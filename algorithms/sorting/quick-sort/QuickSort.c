int partition(int arr[], int start, int end) {
  int pivot = arr[end];
  int i = start - 1;

  for (int j = start; j < end; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  i++;
  int temp = arr[i];
  arr[i] = arr[end];
  arr[end] = temp;

  return i;
}

void quick_sort(int arr[], int start, int end) {
  if (start >= end)
    return;

  int pivot = partition(arr, start, end);

  quick_sort(arr, start, pivot - 1);
  quick_sort(arr, pivot + 1, end);
}
