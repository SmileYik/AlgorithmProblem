#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;

  int weight[n], value[n];
  int max_value[m + 1];

  memset(max_value, 0, sizeof(max_value));

  for (int i = 0; i < n; ++i) {
    cin >> weight[i] >> value[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= weight[i]; --j) {
      if (i == 0) {
        max_value[j] = value[i];
      } else {
        max_value[j] = max(max_value[j], max_value[j - weight[i]] + value[i]);
      }
    }
  }

  cout << max_value[m] << endl;
  return 0;
}
