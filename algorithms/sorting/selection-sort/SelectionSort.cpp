#include <vector>
using namespace std;

class SelectionSort {
  vector<int> vec;

public:
  SelectionSort(vector<int> &vec) { this->vec = vec; }

  void sort(vector<int> &vec) {
    int n = vec.size();

    for (int i = 0; i < n - 1; i++) {
      int minIndex = i;

      for (int j = i + 1; j < n; j++) {
        if (vec[j] < vec[minIndex]) {
          minIndex = j;
        }
      }

      if (minIndex != i) {
        swap(vec[i], vec[minIndex]);
      }
    }
  }
};
