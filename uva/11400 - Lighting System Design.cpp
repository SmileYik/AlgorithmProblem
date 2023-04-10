#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
typedef long long ll;
using namespace std;

int v[1005], k[1005], c[1005], l[1005], r[1005], s[1005], ans[1005];

bool sovle() {
  int n;
  cin >> n;
  if (!n) {
    return false;
  }

  memset(v, 0, sizeof(v));
  memset(k, 0, sizeof(v));
  memset(c, 0, sizeof(v));
  memset(l, 0, sizeof(v));
  memset(r, 0, sizeof(r));
  memset(s, 0, sizeof(r));
  memset(ans, 0x70, sizeof(r));

  for (int i = 0; i < n; ++i) {
    cin >> v[i] >> k[i] >> c[i] >> l[i];
    r[i] = i;
  }

  sort(r, r + n, [&](const int& i, const int& j) {
    return v[i] < v[j];
  });

  int idx;
  ans[0] = 0;
  for (int i = 0; i < n; ++i) {
    idx = r[i];
    s[i] = l[idx];
    if (i != 0) {
      s[i] += s[i - 1];
    }
    for (int j = 0; j <= i; ++j) {
      ans[i + 1] = min(ans[i + 1], ans[j] + k[idx] + c[idx] * (s[i] - s[j] + l[r[j]]));
    }
  }
  cout << ans[n] << endl;
  return true;
}
int main() {
  while (sovle());
  return 0;
}
