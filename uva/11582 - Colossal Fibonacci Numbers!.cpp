#include <cstdio>
using namespace std;

unsigned long long f[(int) 1e6 + 1] = { 0 };

unsigned long long fast_pow_mod(unsigned long long a, unsigned long long n, unsigned long long mod) {
  unsigned long long ans = 1;
  while (n) {
    if (n & 1) {
      ans = (ans * a) % mod;
    }
    n >>= 1;
    a = (a * a) % mod;
  }
  return ans;
}

unsigned long long fab(unsigned long long mod) {
  f[0] = 0;
  f[1] = 1;
  for (unsigned long long i = 2; ; i++) {
    f[i] = (f[i - 1] + f[i - 2]) % mod;
    // cout << f[i] << "(" << i << ") ";
    if (f[i] == 1 && f[i - 1] == 0) {
      return i - 1;
    }
  }
  return 0;
}

int main() {
  unsigned long long t, a, b, n;
  unsigned long long last_n, last_m;
  scanf("%llu", &t);
  while (t--) {
    scanf("%llu%llu%llu", &a, &b, &n);
    if (a == 0 || n <= 1) {
      printf("0\n");
      continue;
    }
    unsigned long long m;
    if (last_n == n) {
      m = last_m;
    } else {
      m = fab(n);
      last_n = n;
      last_m = m;
    }

    printf("%lld\n", f[fast_pow_mod(a % m, b, m) % m]);
  }
}
