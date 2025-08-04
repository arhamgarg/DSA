public class BubbleSort {
  public static void bubbleSort(int[] nums) {
    boolean swapped;
    int last = nums.length;

    do {
      swapped = false;

      for (int i = 0; i < last - 1; i++) {
        if (nums[i] > nums[i + 1]) {
          int temp = nums[i];
          nums[i] = nums[i + 1];
          nums[i + 1] = temp;
          swapped = true;
        }
      }
    } while (swapped);
  }
}