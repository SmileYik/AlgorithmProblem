#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
typedef long long ll;
using namespace std;

int min_wait_time = 1 << 30;
int dp[201][51];

void dfs(int cur_time, int cur_station, int wait_time, int T, int N, int M1, int M2, int* a, int* b, int* sum_t, int* sum_t_rev) {
  // cout << cur_time << "(" << cur_station << ") ";
  if (cur_time == T) {
    if (cur_station == N) {
      min_wait_time = min(min_wait_time, wait_time);
    }
    return;
  } else if (cur_time > T || wait_time >= min_wait_time || wait_time > T) {
    return;
  }
  // M1(a)
  for (int i = 1; i <= M1; ++i) {
    if (sum_t[cur_station - 1] + a[i] == cur_time) {
      dfs(sum_t[cur_station] + a[i], cur_station + 1, wait_time, T, N, M1, M2, a, b, sum_t, sum_t_rev);
    }
  }
  // Wait a second
  if (wait_time + 1 <= min_wait_time) {
    dfs(cur_time + 1, cur_station, wait_time + 1, T, N, M1, M2, a, b, sum_t, sum_t_rev);
  }
  // M2(b)
  for (int i = 1; i <= M2; ++i) {
    if (b[i] + sum_t_rev[N - cur_station + 1] == cur_time) {
      dfs(b[i] + sum_t_rev[N - cur_station + 1], cur_station + 1, wait_time, T, N, M1, M2, a, b, sum_t, sum_t_rev);
    }
  }
}

bool solve(int test_case) {
  int n;
  cin >> n;
  if (!n) {
    return false;
  }

  int T;
  cin >> T;
  int t[n];
  int sum_t[n], sum_t_rev[n + 1];
  sum_t[0] = 0;
  for (int i = 1; i < n; ++i) {
    cin >> t[i];
    sum_t[i] = sum_t[i - 1] + t[i];
  }
  sum_t_rev[n] = sum_t_rev[0] = 0;
  sum_t_rev[n - 1] = t[n - 1];
  for (int i = n - 2; i >= 1; --i) {
    sum_t_rev[i] = sum_t_rev[i + 1] + t[i];
  }

  int M1;
  cin >> M1;
  int a[M1 + 1];
  for (int i = 1; i <= M1; ++i) {
    cin >> a[i];
  }

  int M2;
  cin >> M2;
  int b[M2 + 1];
  for (int i = 1; i <= M2; ++i) {
    cin >> b[i];
  }

  dfs(0, 1, 0, T, n, M1, M2, a, b, sum_t, sum_t_rev);

  printf("Case Number %d: ", test_case);
  if (min_wait_time == (1 << 30)) {
    printf("impossible\n");
  } else {
    printf("%d\n", min_wait_time);
  }

  return true;
}

int main() {

  int test_case = 1;
  while (solve(test_case));
  return 0;
}
