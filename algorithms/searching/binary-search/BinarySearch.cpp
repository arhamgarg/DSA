#include <vector>
using namespace std;

class Searching {
public:
  static int binarySearch(vector<int> &arr, int target) {
    int start = 0, end = arr.size() - 1, mid;

    while (start <= end) {
      mid = start + (end - start) / 2;

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
};
