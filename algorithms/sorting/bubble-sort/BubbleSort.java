public class BubbleSort {
  public static void bubbleSort(int[] nums) {
    if (nums == null || nums.length < 2)
      return;

    boolean swapped = true;
    int end = nums.length;

    while (swapped) {
      swapped = false;
      for (int i = 0; i < end - 1; i++) {
        if (nums[i] > nums[i + 1]) {
          int temp = nums[i];
          nums[i] = nums[i + 1];
          nums[i + 1] = temp;
          swapped = true;
        }
      }
      end--;
    }
  }
}
