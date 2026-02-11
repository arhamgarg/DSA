#include <bits/stdc++.h>
using namespace std;

class Item {
public:
  int weight, profit;

  Item(int weight, int profit) {
    weight = this->weight;
    profit = this->profit;
  }
};

bool compare(struct Item a, struct Item b) {
  double r1 = (double)a.profit / a.weight;
  double r2 = (double)b.profit / b.weight;

  return r1 > r2;
}

double fractionalKnapsack(struct Item arr[], int W, int size) {
  sort(arr, arr + size, compare);

  int currWeight = 0;
  double finalProfit = 0.0;

  for (int i = 0; i < size; i++) {
    if (currWeight + arr[i].weight <= W) {
      currWeight += arr[i].weight;
      finalProfit += arr[i].profit;
    } else {
      int remaining = W - currWeight;

      finalProfit += arr[i].profit * ((double)remaining / arr[i].weight);

      break;
    }
  }

  return finalProfit;
}
