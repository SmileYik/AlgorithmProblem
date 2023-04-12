#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

bool sovle() {
  int n, m;
  if (!(cin >> n >> m)) {
    return false;
  }
  map<int, vector<int>> nums;
  int a;
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    nums[a].push_back(i);
  }
  int b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    int idx = 0;
    if (nums.find(b) != nums.end() && nums[b].size() >= a) {
      idx = nums[b].at(a - 1);
    }
    cout << idx << endl;
  }

  return true;
}

int main() {
  while (sovle());
  return 0;
}
