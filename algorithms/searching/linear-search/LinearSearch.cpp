#include <vector>
using namespace std;

int linearSearch(vector<int> vec, int target) {
  for (int i = 0; i < vec.size(); i++) {
    if (vec[i] == target) {
      return i;
    }
  }

  return -1;
}
