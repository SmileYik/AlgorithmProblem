#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

class UnionFind {
private:
  vector<int> parants;
  vector<int> rank;

  int root(int i) {
    while (i != parants[i]) {
      parants[i] = parants[parants[i]];
      i = parants[i];
    }
    return i;
  }
public:
  UnionFind(int size) {
    parants.resize(size);
    rank.resize(size);
    for (int i = 0; i < size; ++i) {
      parants[i] = i;
      rank[i] = 1;
    }
  }

  bool is_union(int i, int j) {
    return root(i) == root(j);
  }

  bool union_it(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) {
      return false;
    }
    if (rank[i] > rank[j]) {
      parants[j] = i;
    } else if (rank[i] < rank[j]) {
      parants[i] = j;
    } else {
      parants[i] = j;
      ++rank[i];
    }
    return true;
  }
};

int u[500501], v[500501], w[500501], r[500501];
ll x[1001], y[1001];

void dfs(vector<int>& picked_subnetworks, vector<vector<int>>& subnetwork_nodes,
         int* subnetwork_cost, int idx, int r_size, int cities, int& min_cost) {
  if (idx == subnetwork_nodes.size()) {
    int cost = 0;
    UnionFind union_find(cities + 1);
    int nodes = 1;
    for (int i : picked_subnetworks) {
      cost += subnetwork_cost[i];
      int size = subnetwork_nodes[i].size();
      for (int j = 1; j < size; ++j) {
        if (union_find.union_it(subnetwork_nodes[i][j - 1], subnetwork_nodes[i][j])) {
          ++nodes;
        }
      }
    }

    for (int i = 0; i < r_size && nodes != cities; ++i) {
      int j = r[i];
      if (union_find.union_it(u[j], v[j])) {
        cost += w[j];
        ++nodes;
      }
    }

    if (cost < min_cost) {
      min_cost = cost;
    }

  } else {
    dfs(picked_subnetworks, subnetwork_nodes, subnetwork_cost, idx + 1, r_size, cities, min_cost);
    picked_subnetworks.push_back(idx);
    dfs(picked_subnetworks, subnetwork_nodes, subnetwork_cost, idx + 1, r_size, cities, min_cost);
    picked_subnetworks.pop_back();
  }
}

int sovle() {
  int cities, subnetworks, tmp;
  scanf("%d%d", &cities, &subnetworks);
  int cost[subnetworks];
  vector<vector<int>> subnetwork_list(subnetworks);
  for (int i = 0; i < subnetworks; ++i) {
    int n;
    scanf("%d%d", &n, cost + i);
    for (int j = 0; j < n; ++j) {
      scanf("%d", &tmp);
      subnetwork_list[i].push_back(tmp);
    }
  }
  int size = 0;
  for (int i = 1; i <= cities; ++i) {
    scanf("%lld%lld", x + i, y + i);
    for (int j = i - 1; j >= 1; --j) {
      u[size] = i;
      v[size] = j;
      w[size] = pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2);
      r[size] = size;
      ++size;
    }
  }

  int nodes = 1;
  UnionFind union_find(cities + 1);
  sort(r, r + size, [&](const int& i, const int& j) {
    return w[i] < w[j];
  });
  int picked_edge_size = 0;
  for (int i = 0; i < size && nodes != cities; ++i) {
    tmp = r[i];
    if (union_find.union_it(u[tmp], v[tmp])) {
      r[picked_edge_size++] = tmp;
      ++nodes;
    }
  }

  int min_cost = 0x7FFFFFFF;
  vector<int> vec;
  dfs(vec, subnetwork_list, cost, 0, picked_edge_size, cities, min_cost);
  return min_cost;
}

int main() {
  int test_case;
  scanf("%d", &test_case);
  while (test_case--) {
    printf("%d\n", sovle());
    if (test_case) {
      printf("\n");
    }
  }
  return 0;
}
