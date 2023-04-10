#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
  ll t, m;
  cin >> t >> m;
  ll value[m], need_time[m];
  for (ll i = 0; i < m; ++i) {
    cin >> need_time[i] >> value[i];
  }

  ll max_value[t + 1];
  memset(max_value, 0, sizeof(max_value));

  for (ll i = 0; i < m; ++i) {
    for (ll j = need_time[i]; j <= t; ++j) {
      max_value[j] = max(max_value[j], max_value[j - need_time[i]] + value[i]);
    }
  }
  cout << max_value[t] << endl;
  return 0;
}
