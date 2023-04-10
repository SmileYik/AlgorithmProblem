#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

#define INF 0x7FFFFFFF

using namespace std;

class UnionFind {
private:
  vector<int> parents; // 根节点
  int parts;           // 不连通部分

  int root(int i) {
    while (i != parents[i]) {
      parents[i] = parents[parents[i]];
      i = parents[i];
    }
    return i;
  }
public:
  UnionFind(int size) : parts(size) {
    parents.resize(size + 1);
    for (int i = 0; i <= size; ++i) {
      parents[i] = i;
    }
  }

  bool union_it(int i, int j) {
    int i_r = root(i);
    int j_r = root(j);
    if (i_r != j_r) {
      parents[i_r] = j_r;
      --parts;
      return true;
    }
    return false;
  }

  bool is_union(int i, int j) {
    return root(i) == root(j);
  }

  int get_size() const {
    return parts;
  }
};

bool sovle() {
  int n, m;
  scanf("%d%d", &n, &m);
  if (n == 0 && m == 0) {
    return false;
  }
  int u[m], v[m], w[m], r[m];

  if (m == 0) {
    printf("%d\n", n == 1 ? 0 : -1);
    return true;
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", u + i, v + i, w + i);
    r[i] = i;
  }
  sort(r, r + m, [&](const int& i, const int& j) {
    return w[i] < w[j];
  });
  int min_weight = INF;
  for (int left = 0; left < m; ++left) {
    int lowest = -1;
    int highest = -1;
    UnionFind union_find(n);
    for (int i = left; i < m; ++i) {
      int j = r[i];
      // printf("%d ", j);
      if (union_find.union_it(u[j], v[j])) {
        if (lowest == -1) {
          lowest = j;
        }
        highest = j;
        if (union_find.get_size() == 1) {
          if (w[j] - w[lowest] < min_weight) {
            min_weight = w[j] - w[lowest];
          }
          // cout << min_weight << " ";
          break;
        }
      }
    }
    // printf("\n");
  }

  if (min_weight == INF) {
    min_weight = -1;
  }
  printf("%d\n", min_weight);
  return true;
}

int main() {
  while (sovle());
  return 0;
}
