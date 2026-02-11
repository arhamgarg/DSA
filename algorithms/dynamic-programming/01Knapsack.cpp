#include <bits/stdc++.h>
using namespace std;

void binaryKnapsack(int W, vector<int> weights, vector<int> benefits,
                    vector<int> B) {
  for (int k = 0; k < (int)weights.size(); k++) {
    int w_k = weights[k];
    int b_k = benefits[k];

    for (int w = W; w >= w_k; w--) {
      if (B[w - w_k] + b_k > B[w]) {
        B[w] = B[w - w_k] + b_k;
      }
    }
  }

  cout << "Items: " << B[W - weights[(int)weights.size() - 1]] << ", "
       << benefits[(int)benefits.size() - 1] << "\n";
  cout << "Total Profit: " << B[W] << "\n";
}
