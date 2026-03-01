public class ZeroOneKnapsack {
  public static void binaryKnapsack(
      int W, int[] weights, int[] benefits, int[] B) {
    for (int k = 0; k < weights.length; k++) {
      int w_k = weights[k];
      int b_k = benefits[k];

      for (int w = W; w >= w_k; w--) {
        if (B[w - w_k] + b_k > B[w]) {
          B[w] = B[w - w_k] + b_k;
        }
      }
    }

    System.out.println("Items: " + B[W - weights[weights.length - 1]] + ", "
        + benefits[benefits.length - 1]);
    System.out.println("Total Profit: " + B[W]);
  }
}
