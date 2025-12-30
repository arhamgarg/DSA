#include <vector>
using namespace std;

void insertionSort(vector<double> &bucket) {
  for (int i = 1; i < bucket.size(); i++) {
    double key = bucket[i];
    int j = i - 1;

    while (j >= 0 && bucket[j] > key) {
      bucket[j + 1] = bucket[j];
      j--;
    }

    bucket[j + 1] = key;
  }
}

void bucketSort(vector<int> &arr) {
  int n = arr.size();
  vector<double> b[n];

  for (int i = 0; i < n; i++) {
    int bi = n * arr[i];

    b[bi].push_back(arr[i]);
  }

  for (int i = 0; i < n; i++) {
    insertionSort(b[i]);
  }

  int index = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < b[i].size(); j++) {
      arr[index++] = b[i][j];
    }
  }
}
