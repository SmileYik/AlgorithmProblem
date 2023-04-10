#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main() {
  int test_case;
  scanf("%d", &test_case);
  while (test_case--) {
    int n;
    scanf("%d", &n);
    int cache[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", cache + i);
    }
    int left = 0, right = 0, max_length = 0;
    set<int> checked;
    while (right < n) {
      while (right < n && !checked.count(cache[right])) {
        checked.insert(cache[right++]);
      }
      max_length = max(max_length, right - left);
      checked.erase(cache[left++]);
    }
    printf("%d\n", max_length);
  }
}

