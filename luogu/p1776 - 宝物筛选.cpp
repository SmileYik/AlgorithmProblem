#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main() {
  int n, w;
  cin >> n >> w;
  int value[n], weight[n], count[n];
  for (int i = 0; i < n; ++i) {
    cin >> value[i] >> weight[i] >> count[i];
  }

  int max_value[w + 1];
  memset(max_value, 0, sizeof(max_value));
  for (int i = 0; i < n; ++i) {
    for (int j = weight[i]; j <= w; ++j) {
      if (j / weight[i] == count[i] + 1) {
        break;
      }
      max_value[j] = max(max_value[j], max_value[j - weight[i]] + value[i]);

    }
  }
  cout << max_value[w] << endl;
  return 0;
}
