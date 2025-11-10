#include <vector>
using namespace std;

class OrderAgnosticBinarySearch {
public:
  static int OrderAgnosticSearch(vector<int> &arr, int target) {
    if (arr.empty())
      return -1;

    int low = 0;
    int high = arr.size() - 1;
    bool ascending = arr[low] < arr[high];

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (arr[mid] == target)
        return mid;

      if (ascending) {
        if (target < arr[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        if (target > arr[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
    }
    return -1;
  }
};
