#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int test_case;
  cin >> test_case;
  bool first = true;
  while (test_case--) {
    if (first) {
      first = false;
    } else {
      cout << "\n";
    }
    int n, m;
    cin >> n >> m;
    int count = 0;
    int nums[n];
    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
    }
    sort(nums, nums + n);
    int l = 0, r = n - 1;
    while (l <= r) {
      if (l != r && nums[l] + nums[r] <= m) {
        // cout << nums[l] << " " << nums[r] << " | ";
        ++count;
        ++l;
        --r;
      } else {
        // cout << nums[r] << " | ";
        ++count;
        --r;
      }
    }
    cout << count << "\n";
  }
  return 0;
}
