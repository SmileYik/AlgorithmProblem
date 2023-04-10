#include <iostream>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll& x, ll& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  } else {
    ll d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
  }
}

int main() {
  ll a, b, x, y, d;
  while (cin >> a >> b) {
    x = 1;
    y = 0;
    ll x1 = 0, y1 = 1;
    while (b) {
      ll q = a / b;
      ll tmp_a = a;
      ll tmp_x = x;
      ll tmp_y = y;
      x = x1;
      x1 = tmp_x - q * x1;
      y = y1;
      y1 = tmp_y - q * y1;
      a = b;
      b = tmp_a - q * b;
    }
    d = a;
    cout << x << " " << y << " " << d << "\n";
  }
  return 0;
}
