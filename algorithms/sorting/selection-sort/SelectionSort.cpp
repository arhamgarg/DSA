#include <vector>
using namespace std;

class SelectionSort {
  vector<int> arr;

public:
  SelectionSort(vector<int> &arr) { this->arr = arr; }

  void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
      int minIndex = i;

      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[minIndex]) {
          minIndex = j;
        }
      }

      if (minIndex != i) {
        swap(arr[i], arr[minIndex]);
      }
    }
  }
};
