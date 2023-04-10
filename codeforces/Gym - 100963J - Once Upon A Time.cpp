#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

// ll exgcd(ll a, ll b, ll& x, ll& y) {
//   ll x1 = y, y1 = x, tmp, q;
//   while (b) {
//     q = a / b;
//     tmp = x;
//     x = x1;
//     x1 = tmp - q * x1;
//     tmp = y;
//     y = y1;
//     y1 = tmp - q * y1;
//     tmp = a;
//     a = b;
//     b = tmp - q * b;
//   }
//   return a;
// }
ll exgcd(ll a, ll b, ll& x, ll& y) {
  ll res = 0;
  if (!b) {
    res = a;
    x = 1;
    y = 0;
  } else {
    res = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  return res;
}

ll solve_way_1(ll j, ll p, ll q, ll d) {
  ll x, y;
  ll gcd = exgcd(p, -q, x, y);
  ll c = d - j;
  ll k = c / gcd;
  if (c % gcd) {
    return -1;
  }

  ll bd = -q / gcd;
  if (bd < 0) {
    bd = -bd;
  }
  while (x <= 0) {
    x += bd;
  }
  x %= bd;
  while (x <= 0) {
    x += bd;
  }
  y = (c - q * x) / (-p);
  return x * p + j;
}

int main() {
  ll j, p, q, d, result;
  while (cin >> j >> p >> q >> d) {
    if (j == 0 && p == 0 && q == 0 && d == 0) {
      break;
    }
    result = solve_way_1(j, p, q, d);
    if (result == -1) {
      cout << "Impossible\n";
    } else {
      cout << result << endl;
    }
  }
  return 0;
}
