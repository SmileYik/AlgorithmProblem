#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> parent;
vector<int> parent_rank;

inline void init_union_find(int size) {
  parent.resize(size);
  parent_rank.resize(size);
  for (int i = 0; i < size; ++i) {
    parent[i] = i;
    parent_rank[i] = 1;
  }
}

inline int root(int i) {
  while (i != parent[i]) {
    parent[i] = parent[parent[i]];
    i = parent[i];
  }
  return i;
}

inline bool is_connected(int i, int j) {
  return root(i) == root(j);
}

inline bool union_element(int p, int q) {
  p = root(p);
  q = root(q);
  if (p == q) {
    return false;
  } else if (parent_rank[p] > parent_rank[q]) {
    parent[q] = p;
  } else if (parent_rank[q] > parent_rank[p]) {
    parent[p] = q;
  } else {
    parent[p] = q;
    ++parent_rank[q];
  }
  return true;
}

int main() {
  int a, b, ans = 0;;
  init_union_find(100005);
  while ((cin >> a)) {
    if (a == -1) {
      cout << ans << endl;
      ans = 0;
      init_union_find(100005);
      continue;
    }
    cin >> b;
    // cout << a << " " << b << endl;
    if (!union_element(a, b)) {
      ++ans;
    }
  }

  return 0;
}
