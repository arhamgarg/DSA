#include <vector>
using namespace std;

class BubbleSort {
  vector<int> vec;

public:
  BubbleSort(vector<int> &vec) { vec = vec; }

  void sort(vector<int> &vec) {
    int n = vec.size();

    for (int i = 0; i < n - 1; i++) {
      bool isSwapped = false;

      for (int j = 0; j < n - i - 1; j++) {
        if (vec[j] > vec[j + 1]) {
          swap(vec[j], vec[j + 1]);
          isSwapped = true;
        }
      }

      if (!isSwapped) {
        return;
      }
    }
  }
};
