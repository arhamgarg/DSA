#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int jumpSearch(const vector<int> &arr, int target) {
  if (arr.empty()) {
    return -1;
  }

  int step = static_cast<int>(sqrt(arr.size()));
  int previous = 0;

  while (previous < static_cast<int>(arr.size()) &&
         arr[min(step, static_cast<int>(arr.size())) - 1] < target) {
    previous = step;
    step += static_cast<int>(sqrt(arr.size()));

    if (previous >= static_cast<int>(arr.size())) {
      return -1;
    }
  }

  while (previous < min(step, static_cast<int>(arr.size())) &&
         arr[previous] < target) {
    previous++;
  }

  if (previous < static_cast<int>(arr.size()) && arr[previous] == target) {
    return previous;
  }

  return -1;
}
