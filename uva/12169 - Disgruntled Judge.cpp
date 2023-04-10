#include <iostream>
using namespace std;
typedef long long ll;

ll fomulate(ll a, ll b, ll x) {
  return (((a * x) % 10001) + b) % 10001;
}

void ex_gcd(ll a, ll b, ll& d, ll& x, ll& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    ex_gcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}

int main() {
  int t;
  cin >> t;
  ll t2 = t << 1;
  ll nums[t2 + 2];
  for (int i = 0; i < t2; i += 2) {
    cin >> nums[i];
    cout << nums[i] << " ";
  }
  // x = (ax + b) % 10001
  for (ll a = 0; a <= 10000; ++a) {
    // x2 = x1 * a + b
    // x3 = (x1 * a + b) * a + b
    // x3 = x1 * a * a + (a + 1) * b
    ll b = ((nums[2] - a * ((a * nums[0]) % 10001)) / (a + 1)) % 10001;
    ll i = 0;
    bool flag = true;
    for (i = 1; i < t2 - 1; i += 2) {
      nums[i] = fomulate(a, b, nums[i - 1]);
      // cout << fomulate(a, b, nums[i]) << " == " << nums[i + 1] << "\n";
      if (fomulate(a, b, nums[i]) != nums[i + 1]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      cout << "\n " << i << " " << b << " " << " " << a << " \n";
      for (i = 0; i < t2; i += 1) {
        cout << nums[i] << " ";
      }
      cout << "\n";
    }

  }
}
