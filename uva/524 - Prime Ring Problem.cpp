#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int prime_cache[33];
int check[17];

bool is_prime(int i) {
  if (!prime_cache[i]) {
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        prime_cache[i] = -1;
        break;
      }
    }
    if (!prime_cache[i]) {
      prime_cache[i] = 1;
    }
  }
  return prime_cache[i] == 1;
}

void search(vector<int>& ans, int n, int cur, int* used) {
  if (cur == n) {
    if (is_prime(ans.back() + 1)) {
      for (int i = 0; i < n; ++i) {
        cout << ans[i];
        if (i != n - 1) {
          cout << " ";
        }
      }
      cout << "\n";
    }
  } else {
    for (int i = 2; i <= n; ++i) {
      if (!used[i] && is_prime(ans.back() + i)) {
        ans.push_back(i);
        used[i] = 1;
        search(ans, n, cur + 1, used);
        used[i] = 0;
        ans.pop_back();
      }
    }
  }
}

int main() {
  int n;
  int cnt = 1;
  while (cin >> n) {
    if (cnt != 1) {
      cout << "\n";
    }
    cout << "Case " << cnt++ << ":\n";
    vector<int> ans;

    memset(check, 0, sizeof(check));
    ans.push_back(1);
    check[1] = 1;
    search(ans, n, 1, check);
  }
  return 0;
}
