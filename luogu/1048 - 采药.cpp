#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int t, m;
int need_time[103];
int value[103];
int max_value[103][1003] = {0};

int dfs(int i, int cur_time) {
  if (max_value[i][cur_time]) {
    return max_value[i][cur_time];
  } else if (i == m + 1) {
    return 0;
  }
  max_value[i][cur_time] = max(
    dfs(i + 1, cur_time),
    cur_time >= need_time[i] ? (dfs(i + 1, cur_time - need_time[i]) + value[i]) : -1
  );
  return max_value[i][cur_time];
}

int main() {
  cin >> t >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> need_time[i] >> value[i];
  }
  cout << dfs(1, t) << endl;
}
