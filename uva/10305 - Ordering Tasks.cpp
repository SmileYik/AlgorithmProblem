#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

bool dfs(map<int, set<int>>& edges, map<int, bool>& check, vector<int>& ans, int i) {
  check[i] = false;
  if (edges.count(i)) {
    for (int a : edges[i]) {
      if (check.count(a)) {
        if (!check[a]) {
          return false;
        }
      } else if (!dfs(edges, check, ans, a)) {
        return false;
      }
    }
  }
  ans.insert(ans.begin(), i);
  check[i] = true;
  return true;
}

int main() {
  int n, m, a, b;
  while (cin >> n >> m && n != 0) {
    map<int, set<int>> p_map;
    map<int, bool> checked;
    while (m-- && cin >> a >> b) {
      if (!p_map.count(a)) {
        p_map[a] = set<int>();
      }
      p_map[a].insert(b);
    }
    vector<int> ans;
    bool flag = false;
    while (!flag) {
      for (int i = 1; i <= n; ++i) {
        if (checked.find(i) != checked.end()) {
          continue;
        }
        flag = dfs(p_map, checked, ans, i);
      }
    }

    b = ans.size() - 1;
    for (a = 0; a <= b; ++a) {
      cout << ans[a];
      if (b != a) {
        cout << " ";
      }
    }
    cout << "\n";
  }

  return 0;
}
