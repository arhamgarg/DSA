#include <vector>
using namespace std;

class Sorter {
private:
  vector<int> vec;

public:
  Sorter(vector<int> &v) : vec(v) {}

  void insertionSort(vector<int> &vec) {
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
