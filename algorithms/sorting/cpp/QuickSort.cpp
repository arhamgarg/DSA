#include <vector>
using namespace std;

class Sorter {
private:
  vector<int> vec;

public:
  Sorter(vector<int> &v) : vec(v) {}

  int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
      if (vec[j] <= pivot) {
        i++;
        swap(vec[i], vec[j]);
      }
    }

    swap(vec[i + 1], vec[high]);
    return (i + 1);
  }

  void quickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
      int pi = partition(vec, low, high);

      quickSort(vec, low, pi - 1);
      quickSort(vec, pi + 1, high);
    }
  }
};
