#include <iostream>

using namespace std;
typedef long long ll;

/**
 * count = n * (1 - P_i)
 */
int euler_phi(int n) {
  int count = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      count = count / i * (i - 1);
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  if (n > 1) {
    count = count / n * (n - 1);
  }
  return count;
}

int main() {
  ll n;
  while (cin >> n && n) {
    if (n == 1) {
      cout << 0 << endl;
    } else {
      cout << euler_phi(n) << endl;
    }
  }
  return 0;
}
