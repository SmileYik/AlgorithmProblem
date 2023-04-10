#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

struct MatSize {
  int a, b;
  bool canReformTo(const MatSize& size) const {
    return a < size.a && b < size.b || a < size.b && b < size.a;
  }
};

int mat[100][100];

int dp(int*d, int i, int& n) {
  if (d[i] > 0) {
    return d[i];
  }
  d[i] = 1;
  for (int j = 0; j < n; ++j) {
    if (mat[i][j]) {
      d[i] = max(d[i], dp(d, j, n) + 1);
    }
  }
  return d[i];
}

int main() {
  int n;
  cin >> n;
  MatSize sizes[n];
  for (int i = 0; i < n; ++i) {
    cin >> sizes[i].a >> sizes[i].b;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      mat[i][j] = sizes[i].canReformTo(sizes[j]);
      mat[j][i] = sizes[j].canReformTo(sizes[i]);
    }
  }

  int d[n];
  memset(d, -1, sizeof(d));
  cout << dp(d, 0, n) << endl;
}
