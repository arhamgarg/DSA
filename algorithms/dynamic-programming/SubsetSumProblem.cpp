#include <vector>
using namespace std;

int subsetSum(vector<int> &arr, int target) {
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  dp[0][0] = 0;

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }

  for (int i = 0; i <= target; i++) {
    dp[0][i] = 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= target; j++) {
      dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
    }
  }

  return dp[n][target];
}