import java.util.Scanner;

public class AgnosticBinary {
   public static void main(String[] args) {
        int[] arr = {40, 10, 5, 2, 1}; // descending array
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the target to find:");
        int target = scanner.nextInt();
        scanner.close();

        // Order-agnostic binary search
        int order_binary = order_agnostic(arr, target);
        System.out.println("The target " + target + " is found at index: " + order_binary);
    }

    public static int order_agnostic(int[] arr, int target) {
        if (arr == null || arr.length == 0) return -1;
        int low = 0, high = arr.length - 1;
        boolean ascending = arr[low] < arr[high]; // check order

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) return mid;

            if (ascending) {
                if (target < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // descending order
                if (target > arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
}
