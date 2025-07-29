#include <vector>
using namespace std;

class InsertionSort {
  vector<int> vec;

public:
  InsertionSort(vector<int> &vec) { this->vec = vec; }

  void sort(vector<int> &vec) {
    int n = vec.size();

    for (int i = 1; i < n; i++) {
      int key = vec[i];
      int j = i - 1;

      while (j >= 0 && vec[j] > key) {
        vec[j + 1] = vec[j];
        j--;
      }

      vec[j + 1] = key;
    }
  }
};
