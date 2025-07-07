#include <vector>
using namespace std;

class Sorter {
private:
  vector<int> vec;

public:
  Sorter(vector<int> &v) : vec(v) {}

  void merge(vector<int> &vec, int l, int r, int m) {
    vector<int> temp;

    int left = l;
    int right = m + 1;

    while (left <= m && right <= r) {
      if (vec[left] < vec[right]) {
        temp.push_back(vec[left]);
        left++;
      } else {
        temp.push_back(vec[right]);
        right++;
      }
    }

    while (left <= m) {
      temp.push_back(vec[left]);
      left++;
    }

    while (right <= r) {
      temp.push_back(vec[right]);
      right++;
    }

    for (int i = l; i <= r; i++) {
      vec[i] = temp[i - l];
    }
  }

  void mergeSort(vector<int> &vec, int l, int r) {
    if (l < r) {
      int mid = (l + r) / 2;

      mergeSort(vec, l, mid);
      mergeSort(vec, mid + 1, r);

      merge(vec, l, r, mid);
    }
  }
};
