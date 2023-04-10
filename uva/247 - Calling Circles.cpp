#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

class UnionFind {
private:
  vector<int> parent;
  vector<int> rank;

  int root(int i) {
    while (i != parent[i]) {
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }
public:
  UnionFind() {}
  UnionFind(int size) {
    parent.resize(size);
    rank.resize(size);
    for (int i = 0; i < size; ++i) {
      parent[i] = i;
      rank[i] = 1;
    }
  }

  bool union_it(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) {
      return false;
    }
    if (rank[i] > rank[j]) {
      parent[j] = i;
    } else if (rank[i] < rank[j]) {
      parent[i] = j;
    } else {
      parent[i] = j;
      ++rank[j];
    }
    return true;
  }

  bool is_union(int i, int j) {
    return root(i) == root(j);
  }

  void union_part(vector<vector<int>>& vec) {
    vec.clear();
    int idx = 0;
    unordered_map<int, int> idx_map;
    int size = parent.size();
    int j, root_idx;
    for (int i = 0; i < size; ++i) {
      root_idx = root(i);
      if (idx_map.count(root_idx)) {
        j = idx_map[root_idx];
      } else {
        j = idx++;
        idx_map[root_idx] = j;
        vec.push_back(vector<int>());
      }
      vec[j].push_back(i);
    }
  }
};

bool sovle(int case_idx) {
  int n, m;
  cin >> n >> m;
  if (!n && !m) {
    return false;
  }
  if (case_idx != 1) {
    cout << "\n";
  }
  string user_a, user_b;
  int idx = 0;
  unordered_map<string, int> user_idx_map;
  string idx_user_map[n];
  bool called[n][n];
  UnionFind union_find(n);
  memset(called, false, sizeof(called));
  for (int i = 0; i < m; ++i) {
    cin >> user_a >> user_b;
    if (!user_idx_map.count(user_a)) {
      idx_user_map[idx] = user_a;
      user_idx_map[user_a] = idx++;
    }
    if (!user_idx_map.count(user_b)) {
      idx_user_map[idx] = user_b;
      user_idx_map[user_b] = idx++;
    }
    called[user_idx_map[user_a]][user_idx_map[user_b]] = true;
  }

  for (int i = 0; i < idx; ++i) {
    for (int j = 0; j < idx; ++j) {
      for (int k = 0; k < idx; ++k) {
        called[j][k] = called[j][k] || (called[j][i] && called[i][k]);
        if (called[j][k] && called[k][j]) {
          union_find.union_it(j, k);
        }
      }
    }
  }

  // for (int i = 0; i < idx; ++i) {
  //   for (int j = i + 1; j < idx; ++j) {
  //     if (called[i][j] && called[j][i]) {
  //       union_find.union_it(i, j);
  //     }
  //   }
  // }

  vector<vector<int>> parts;
  union_find.union_part(parts);
  int size = parts.size();
  cout << "Calling circles for data set " << case_idx << ":\n";
  for (int i = 0; i < size; ++i) {
    int sub_size = parts[i].size() - 1;
    for (int j = 0; j <= sub_size; ++j) {
      cout << idx_user_map[parts[i][j]];
      if (j != sub_size) {
        cout << ", ";
      }
    }
    cout << "\n";
  }

  return true;
}

int main() {
  int idx = 1;
  while (sovle(idx++));
}
