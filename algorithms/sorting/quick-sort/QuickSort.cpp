#include <vector>
using namespace std;

class QuickSort {
  vector<int> vec;

public:
  QuickSort(vector<int> &vec) { this->vec = vec; }

  int partition(vector<int> &vec, int start, int end) {
    int i = start - 1, pivot = vec[end];

    for (int j = start; j < end; j++) {
      if (vec[j] <= pivot) {
        i++;
        swap(vec[i], vec[j]);
      }
    }

    i++;
    swap(vec[i], vec[end]);
    return i;
  }

  void quickSort(vector<int> &vec, int start, int end) {
    if (start < end) {
      int pi = partition(vec, start, end);

      quickSort(vec, start, pi - 1);
      quickSort(vec, pi + 1, end);
    }
  }
};
