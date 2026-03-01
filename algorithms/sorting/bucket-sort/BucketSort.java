import java.util.ArrayList;

public class BucketSort {
  public static void insertionSort(ArrayList<Double> bucket) {
    for (int i = 1; i < bucket.size(); i++) {
      double key = bucket.get(i);
      int j = i - 1;

      while (j >= 0 && bucket.get(j) > key) {
        bucket.set(j + 1, bucket.get(j));
        j--;
      }

      bucket.set(j + 1, key);
    }
  }

  public static void bucketSort(int[] arr) {
    int n = arr.length;
    ArrayList<Double>[] buckets = new ArrayList[n];

    for (int i = 0; i < n; i++) {
      buckets[i] = new ArrayList<>();
    }

    for (int i = 0; i < n; i++) {
      int bi = n * arr[i];
      buckets[bi].add((double) arr[i]);
    }

    for (int i = 0; i < n; i++) {
      insertionSort(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < buckets[i].size(); j++) {
        arr[index++] = buckets[i].get(j).intValue();
      }
    }
  }
}
