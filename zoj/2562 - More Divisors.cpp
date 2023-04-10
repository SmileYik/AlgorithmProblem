#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll primes[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

bool is_prime(ll n) {
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void dfs(int prime_idx, ll& max_n, ll& lowest_num, ll cur_n, ll cur_num, ll& max) {
  if (cur_n > max_n || (cur_n == max_n && lowest_num > cur_num)) {
    max_n = cur_n;
    lowest_num = cur_num;
  }
  if (prime_idx <= 17) {
    for (int i = 1; ; ++i) {
      cur_num *= primes[prime_idx];
      if (cur_num > max) {
        break;
      }
      dfs(prime_idx + 1, max_n, lowest_num, cur_n * (i + 1), cur_num, max);
    }
  }
}

int main() {
  ll n;
  while (cin >> n) {
    ll max_n = 0;
    ll lowest_num = 1ll << 63;
    dfs(1, max_n, lowest_num, 1, 1, n);
    cout << lowest_num << endl;
  }
}
