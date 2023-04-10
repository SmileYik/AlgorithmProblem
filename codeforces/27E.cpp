#include <algorithm>
#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll primes[1001];
ll primes_size = 0;


bool is_prime(ll n) {
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void dfs(ll tmp, ll tmp_n, ll n, ll& lowest_ans, ll max_times, int prime_idx) {
  if (tmp_n == n && tmp < lowest_ans) {
    lowest_ans = tmp;
  } else if (tmp_n < n && prime_idx < primes_size) {
    for (int i = 1; i < max_times; ++i) {
      tmp *= primes[prime_idx];
      if (tmp > lowest_ans) {
        break;
      }
      dfs(tmp, tmp_n * (1 + i), n, lowest_ans, 65, prime_idx + 1);
    }
  }
}

int main() {
  ll n;
  cin >> n;
  for (ll i = 1; i <= 100; ++i) {
    if (is_prime(i)) {
      primes[primes_size++] = i;
    }
  }

  ll ans = 1;
  ll lowest_ans = 1ll << 60;
  dfs(ans, 1, n, lowest_ans, 65, 1);
  cout << lowest_ans << endl;
}
