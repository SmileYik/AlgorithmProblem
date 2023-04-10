#include <cstring>
#include <iostream>
#include <unordered_map>
#define MAX_N 2000001
using namespace std;

typedef long long ll;

ll phi[MAX_N];
ll depth_phi_cache[MAX_N];

void phi_table() {
  memset(phi, 0, sizeof(phi));
  phi[1] = 1;
  for (int i = 2; i < MAX_N; ++i) {
    if (!phi[i]) {
      for (int j = i; j < MAX_N; j += i) {
        if (!phi[j]) {
          phi[j] = j;
        }
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}

ll depth_phi(ll n) {
  if (depth_phi_cache[n]) {
    return depth_phi_cache[n];
  }
  ll tmp = n;
  ll depth = 0;
  while (n != 1) {
    n = phi[n];
    ++depth;
  }
  depth_phi_cache[tmp] = depth;
  return depth;
}

ll sodf(ll m, ll n) {
  ll sum = 0;
  while (m <= n) {
    // cout << m << ": " << depth_phi(m) << "; ";
    sum += depth_phi(m++);
  }
  return sum;
}

int main() {
  memset(depth_phi_cache, 0, sizeof(depth_phi_cache));
  ll test_case, m, n;
  phi_table();
  cin >> test_case;
  while (test_case--) {
    cin >> m >> n;
    cout << sodf(m, n) << endl;
  }
}


