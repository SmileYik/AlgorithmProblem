#include <iostream>
#include <cmath>
#include <set>
#include <cstring>
using namespace std;

class Node {
public:
  int num;
  int rev_length;
  Node() {}
  Node(int n, int r) : num(n), rev_length(r) {}
};

int main() {
  int test_case;
  cin >> test_case;
  while (test_case--) {
    int n;
    cin >> n;
    if (n <= 1) {
      cout << n << "\n";
      continue;
    }

    int nums[n];
    int nums_length[n];
    int nums_length_rev[n];
    int nums_type[n];
    int type = 0;

    for (int i = 0; i < n; ++i) {
      cin >> nums[i];
      if (i == 0) {
        nums_type[0] = type;
        nums_length[0] = 1;
      } else if (nums[i] > nums[i - 1]) {
        nums_length[i] = nums_length[i - 1] + 1;
        nums_type[i] = type;
      } else {
        nums_length[i] = 1;
        nums_type[i] = type++;
      }
    }

    nums_length_rev[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] < nums[i - 1]) {
        nums_length_rev[i] = nums_length_rev[i + 1] + 1;
      } else {
        nums_length_rev[i] = 1;
      }
    }

    set<Node> s;
    int max_length = 1;
    for (int i = 0; i < n; ++i) {
      auto result = s.lower_bound(Node(nums[i], nums_length[i]));
      if (result != s.begin()) {
        --result;

      }
    }
    cout << max_length << "\n";
  }
}
