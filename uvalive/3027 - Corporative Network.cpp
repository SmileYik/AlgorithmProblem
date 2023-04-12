#include <bits/stdc++.h>
#include <cstring>
typedef long long ll;
using namespace std;

int parent[20010];
int dis[20010]; // to parent.

inline void init_union_find(int size) {
  memset(dis, 0, sizeof(dis));
  for (int i = 0; i < size; ++i) {
    parent[i] = i;
  }
}

inline int find_root(int i) {
  if (i != parent[i]) {
    int x = find_root(parent[i]);
    dis[i] += dis[parent[i]];
    return parent[i] = x;
  }
  return i;
}

inline bool union_element(int i, int j) {
  parent[j] = i;
  dis[j] += abs(i - j) % 1000;
  return true;
}

int main() {
  int t, n;
  cin >> t;
  char opt;
  int a, b;
  while (t--) {
    cin >> n;
    init_union_find(n + 1);
    while ((cin >> opt) && opt != 'O') {
      cin >> a;
      if (opt == 'E') {
        find_root(a);
        cout << dis[a] << endl;
      } else {
        cin >> b;
        union_element(b, a);
      }
    }
  }
  return 0;
}
