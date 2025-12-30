#include <vector>
using namespace std;

int orderAgnosticBinarySearch(vector<int> &arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  bool ascending = arr[low] <= arr[high];

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    if (ascending) {
      if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    } else {
      if (arr[mid] < target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
  }

  return -1;
}
