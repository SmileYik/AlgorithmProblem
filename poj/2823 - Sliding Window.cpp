#include <deque>
#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int nums[n];
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  deque<int> up, down;
  int ans_up[n - k + 1], ans_down[n - k + 1];
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    if (i >= k) {
      ans_up[idx] = down.front();
      ans_down[idx++] = up.front();
    }

    while (!up.empty() && up.back() > nums[i]) {
      up.pop_back();
    }
    while (!down.empty() && down.back() < nums[i]) {
      down.pop_back();
    }
    up.push_back(nums[i]);
    down.push_back(nums[i]);
    if (i >= k) {
      while (!up.empty() && nums[i - k] == up.front()) {
        up.pop_front();
      }
      while (!down.empty() && nums[i - k] == down.front()) {
        down.pop_front();
      }
    }
  }
  ans_up[idx] = down.front();
  ans_down[idx++] = up.front();
  for (int i = 0; i < idx; ++i) {
    cout << ans_down[i];
    if (i == idx - 1) {
      cout << "\n";
    } else {
      cout << " ";
    }
  }

  for (int i = 0; i < idx; ++i) {
    cout << ans_up[i];
    if (i == idx - 1) {
      cout << "\n";
    } else {
      cout << " ";
    }
  }

  return 0;
}
