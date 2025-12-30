#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int target) {
  int start = 0;
  int end = arr.size() - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return -1;
}
