#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
typedef long long ll;
using namespace std;
ll matrix[105][105];
ll ans[105][105];

void dfs(ll number, ll idx, ll* path, ll& m, ll& n, bool& flag) {
  if (flag == true) {
    return;
  } else if (idx == n) {
    flag = true;
    for (ll i = 0; i < n; ++i) {
      cout << path[i] << (i == n - 1 ? "\n" : " ");
    }
    return;
  }

  priority_queue<ll, vector<ll>, greater<ll>> q;
  for (ll i = 2; i >= 0; --i) {
    q.push((path[idx - 1] - i + m) % m);
  }

  while (!q.empty()) {
    ll k = q.top();
    q.pop();
    if (number == ans[k][idx]) {
      ll tmp = path[idx];
      path[idx] = k + 1;
      dfs(number - matrix[k][idx], idx + 1, path, m, n, flag);
      path[idx] = tmp;
    }
  }
}

bool sovle() {
  ll m, n;
  if (!(cin >> m >> n)) {
    return false;
  }
  for (ll i = 0; i < m; ++i) {
    for (ll j = 0; j < n; ++j) {
      cin >> matrix[i][j];
    }
  }
  memset(ans, 0, sizeof(ans));

  for (ll i = 0; i < m; ++i) {
    ans[i][n - 1] = matrix[i][n - 1];
  }

  for (ll j = n - 2; j >= 0; --j) {
    for (ll i = 0; i < m; ++i) {
      ans[i][j] = min(ans[i][j + 1], min(
        ans[(i + 1) % m][j + 1],
        ans[(i + m - 1) % m][j + 1]
      )) + matrix[i][j];

    }
  }
  ll aans = 0x70707070;
  ll ppath[n];
  ll tmp;
  for (ll i = 0; i < m; ++i) {
    if (aans > ans[i][0]) {
      aans = ans[i][0];
      ppath[0] = i + 1;
      tmp = aans - matrix[i][0];
    }
  }
  bool flag = false;
  dfs(tmp, 1, ppath, m, n, flag);

  cout << aans << endl;
  return true;
}

int main() {
  while (sovle());
  return 0;
}
