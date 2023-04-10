#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
typedef long long ll;
using namespace std;

void sovle(int test_case) {
  int n, t;
  cin >> n >> t;
  int song_count[t];
  int song_time;
  memset(song_count, -1, sizeof(song_count));
  song_count[0] = 0;
  int max_count = 0, max_time = 0;
  for (int i = 0; i < n; ++i) {
    cin >> song_time;
    // for (int j = song_time; j < t; ++j) {
    for (int j = t - 1; j >= 0; --j) {
      if (j - song_time >= 0 && song_count[j - song_time] > -1) {
        song_count[j] = max(song_count[j - song_time] + 1, song_count[j]);
      }
      if (max_count < song_count[j]) {
        max_count = song_count[j];
        max_time = j;
      }
      if (max_count == song_count[j]) {
        max_time = max(j, max_time);
      }
    }
  }

  cout << "Case " << test_case << ": " << max_count + 1 << " " << max_time + 678 << "\n";

}

int main() {
  int test_case;
  cin >> test_case;
  for (int i = 1; i <= test_case; ++i) {
    sovle(i);
  }
  return 0;
}
