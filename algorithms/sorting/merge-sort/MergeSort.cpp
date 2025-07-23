#include <vector>
using namespace std;

class MergeSort {
  vector<int> vec;

public:
  MergeSort(vector<int> &vec) { vec = vec; }

  void merge(vector<int> &vec, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end) {
      if (vec[i] < vec[j]) {
        temp.push_back(vec[i]);
        i++;
      } else {
        temp.push_back(vec[j]);
        j++;
      }
    }

    while (i <= mid) {
      temp.push_back(vec[i]);
      i++;
    }

    while (j <= end) {
      temp.push_back(vec[j]);
      j++;
    }

    for (int index = 0; index < temp.size(); index++) {
      vec[index + start] = temp[index];
    }
  }

  void mergeSort(vector<int> &vec, int start, int end) {
    if (start < end) {
      int mid = start + (end - start) / 2;

      mergeSort(vec, start, mid);
      mergeSort(vec, mid + 1, end);

      merge(vec, start, mid, end);
    }
  }
};
