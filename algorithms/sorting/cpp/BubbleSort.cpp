#include <vector>
using namespace std;

class Sorter {
private:
  vector<int> v;

public:
  Sorter(vector<int> &v) : v(v) {}

  void bubbleSort(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
      bool isSwapped = false;

      for (int j = 0; j < n - i - 1; j++) {
        if (v[j] > v[j + 1]) {
          swap(v[j], v[j + 1]);
          isSwapped = true;
        }
      }

      if (!isSwapped) {
        return;
      }
    }
  }
};
