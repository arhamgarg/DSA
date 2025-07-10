#include <vector>
using namespace std;

class Sorter {
private:
  vector<int> v;

public:
  Sorter(vector<int> &v) : v(v) {}

  void selectionSort(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
      int minIndex = i;

      for (int j = i + 1; j < n; j++) {
        if (v[j] < v[minIndex]) {
          minIndex = j;
        }
      }

      if (minIndex != i) {
        swap(v[i], v[minIndex]);
      }
    }
  }
};
