#include <vector>
using namespace std;

class BubbleSort {
  vector<int> arr;

public:
  BubbleSort(vector<int> &arr) { this->arr = arr; }

  void bubbleSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
      bool isSwapped = false;

      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
          isSwapped = true;
        }
      }

      if (!isSwapped) {
        return;
      }
    }
  }
};
