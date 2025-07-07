#include <vector>
using namespace std;

class Sorter {
private:
  vector<int> vec;

public:
  Sorter(vector<int> &v) : vec(v) {}

  void bubbleSort(vector<int> &vec) {
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
