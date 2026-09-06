#include <algorithm>
#include <vector>
using namespace std;

vector<int> countingSort(const vector<int> &arr) {
  if (arr.empty()) {
    return {};
  }

  auto [minimum, maximum] = minmax_element(arr.begin(), arr.end());
  vector<int> counts(*maximum - *minimum + 1, 0);

  for (int value : arr) {
    counts[value - *minimum]++;
  }

  vector<int> sorted;

  for (int i = 0; i < static_cast<int>(counts.size()); i++) {
    sorted.insert(sorted.end(), counts[i], i + *minimum);
  }

  return sorted;
}
