#include <iostream>
using namespace std;
void gcd(int a, int b, int& d, int& x, int& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

int pow_mod(int a, int n, int mod) {
  if (n == 0) {
    return 1;
  }

  long long ans = pow_mod(((a % mod) * (a % mod)) % mod, n >> 1, mod);
  if ((n & 0x1) == 1) {
    ans *= (a % mod);
  }
  return ans % mod;
}

int main() {
  int a, b, d, x, y;
  cin >> a >> b;
  gcd(a, b, d, x, y);
  cout << d << " " << x << " " << y << endl;
  return 0;
}
