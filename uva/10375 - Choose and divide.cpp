#include <algorithm>
#include <cstdio>

typedef long long ll;

ll gcd(ll a, ll b) {
  ll tmp;
  while (b) {
    tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

void sovle(ll a1, ll a2, ll b1, ll b2, ll c1, ll c2, ll d1, ll d2, ll& up, ll& down) {
  up = down = 1;
  ll tmp;
  while (a1 != a2 || b1 != b2 || c1 != c2 || d1 != d2) {
    if (a1 != a2) {
      up *= a1++;
      tmp = gcd(up, down);
      up /= tmp;
      down /= tmp;
    }
    if (b1 != b2) {
      up *= b1++;
      tmp = gcd(up, down);
      up /= tmp;
      down /= tmp;
    }
    if (c1 != c2) {
      down *= c1++;
      tmp = gcd(up, down);
      up /= tmp;
      down /= tmp;
    }
    if (d1 != d2) {
      down *= d1++;
      tmp = gcd(up, down);
      up /= tmp;
      down /= tmp;
    }
  }
}

int main() {
  ll p, q, r, s;
  while (scanf("%lld%lld%lld%lld", &p, &q, &r, &s) > 0) {
    ll up, down;
    sovle(q, p,
          2, r - s,
          2, p - q,
          s, r, up, down);
    printf("%.5lf\n", ((double) up) / down);
  }
  return 0;
}
