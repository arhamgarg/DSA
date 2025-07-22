#include <vector>
using namespace std;

class Sorter {
private:
  vector<int> v;

public:
  Sorter(vector<int> &v) : v(v) {}

  void merge(vector<int> &v, int l, int r, int m) {
    vector<int> temp;

    int left = l;
    int right = m + 1;

    while (left <= m && right <= r) {
      if (v[left] < v[right]) {
        temp.push_back(v[left]);
        left++;
      } else {
        temp.push_back(v[right]);
        right++;
      }
    }

    while (left <= m) {
      temp.push_back(v[left]);
      left++;
    }

    while (right <= r) {
      temp.push_back(v[right]);
      right++;
    }

    for (int i = l; i <= r; i++) {
      v[i] = temp[i - l];
    }
  }

  void mergeSort(vector<int> &v, int l, int r) {
    if (l < r) {
      int mid = (l + r) / 2;

      mergeSort(v, l, mid);
      mergeSort(v, mid + 1, r);

      merge(v, l, r, mid);
    }
  }
};
