#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int path[26][26];
int checked[26];
int has_path[26];
int count[26];

bool is_can_sovle() {
  memset(path, 0, sizeof(path));
  memset(checked, 0, sizeof(checked));
  memset(count, 0, sizeof(count));
  memset(has_path, 0, sizeof(has_path));
  int amount;
  cin >> amount;
  string s;
  while (amount--) {
    cin >> s;
    ++path[s[0] - 'a'][s[s.size() - 1] - 'a'];
    has_path[s[0] - 'a']++;
    has_path[s[s.size() - 1] - 'a']++;
  }

  int odd_count = 0;
  for (int i = 0; i < 26; ++i) {
    if (has_path[i] % 2 == 1) {
      odd_count++;
    }
  }

  if (odd_count > 2) {
    return false;
  }

  int start = s[0] - 'a';
  queue<int> q;
  q.push(start);
  checked[start] = true;
  int left = false;
  int right = false;
  while (!q.empty()) {
    start = q.front();
    q.pop();
    for (int i = 0; i < 26; ++i) {
      int sub;
      if ((path[start][i] || path[i][start]) && !checked[i]) {
        sub = path[start][i] - path[i][start];
        if (abs(sub) > 1) {
          return false;
        } else if (sub < 0) {
          left = !left;
          if (!left) {
            return false;
          }
        } else if (sub > 0) {
          right = !right;
          if (!right) {
            return false;
          }
        }
        q.push(i);
        checked[i] = true;
      }
    }
  }
  for (int i = 0; i < 26; ++i) {
    if (!((has_path[i] > 0 && checked[i]) || (has_path[i] == 0 && checked[i] == false))) {
      return false;
    }
  }
  return true;
}

int main() {
  int test;
  cin >> test;
  while (test--) {
    cout << (is_can_sovle() ? "Ordering is possible.\n" : "The door cannot be opened.\n");
  }
}
