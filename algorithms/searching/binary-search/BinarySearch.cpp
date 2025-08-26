#include <vector>
using namespace std;

class Searching {
public:
  static int binarySearch(vector<int> &vec, int target) {
    int start = 0, end = vec.size() - 1, mid;

    while (start <= end) {
      mid = start + (end - start) / 2;

      if (vec[mid] == target) {
        return mid;
      } else if (vec[mid] < target) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }

    return -1;
  }
};
