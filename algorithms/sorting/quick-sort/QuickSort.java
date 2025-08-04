// Implemented where pivot element is last element
public class QuickSort {
    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swapping
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        int temp = arr[i];
        arr[i] = pivot;
        arr[high] = temp;
        return i; // pivot index
    }

    public static void quicksort(int arr[], int low, int high) {
        if (low < high) {
            int pivot_index = partition(arr, low, high);

            quicksort(arr, low, pivot_index - 1);
            quicksort(arr, pivot_index + 1, high);
        }
    }
}
