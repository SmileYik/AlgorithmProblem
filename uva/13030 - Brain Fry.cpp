#include <bits/stdc++.h>
#include <cstring>
#include <queue>
#define INF 10000
typedef long long ll;
using namespace std;

struct Edge {
  int from, to;
  int weight;
};

struct Node {
  int node;
  int d;

  bool operator > (const Node& n) const {
    return d > n.d;
  }
};

bool vis[255];
bool checked[255][1000];
vector<int> d;
double rate[255];
vector<Edge> edges;
vector<vector<int>> link_edges;

void dfs(int node, int distance, int limit_distance, double cur_rate, double& ans_rate, double& ans_dis) {
  // cout << node << " -> ";
  if (distance >= limit_distance) {
    if (node != 0) {
      ans_rate += cur_rate * rate[node];
      ans_dis += cur_rate * (distance + d[node]);
    }
    return;
  } else if (checked[node][distance]) {
    return;
  } else if (node != 0) {
    ans_rate += cur_rate * rate[node];
    ans_dis += cur_rate * (distance + d[node]) * rate[node];
  }
  if (node != 0)
    cur_rate *= 1 - rate[node];

  const auto& link = link_edges[node];
  int size = 0;
  for (const int& i : link) {
    const Edge& edge = edges[i];
    if (checked[node][distance] || edge.to == 0) {
      continue;
    }
    ++size;
  }
  if (size == 0 && node == 0) {
    // ans_rate += cur_rate;
    // ans_dis += cur_rate * distance;
    return;
  } else if (size == 0) {
    dfs(0, d[node] + distance, limit_distance, cur_rate, ans_rate, ans_dis);
    // ans_dis += cur_rate * (distance + d[node]) * (1 - rate[node]);
    return;
  }
  // cout << "(" << size<<") ";
  cur_rate /= size;
  for (const int& i : link) {
    const Edge& edge = edges[i];
    if (checked[node][distance] || edge.to == 0) {
      continue;
    }
    checked[node][distance] = true;
    dfs(edge.to, edge.weight + distance, limit_distance, cur_rate, ans_rate, ans_dis);
    checked[node][distance] = false;
    // cout << "- ";
  }
}

void sovle(int test_case) {
  cout << "Case " << test_case << ": ";
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 1; i <= n; ++i) {
    cin >> rate[i];
  }
  edges.clear();
  link_edges.clear();
  link_edges.resize(n + 1);
  int u, v, w;
  int edge_size = 0;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
    edges.push_back({v, u, w});
    link_edges[u].push_back(edge_size++);
    link_edges[v].push_back(edge_size++);
  }

  memset(vis, 0, sizeof(vis));
  d = vector<int>(n + 1, INF);
  d[0] = 0;
  priority_queue<Node, vector<Node>, greater<Node>> q;
  q.push({0, 0});
  while (!q.empty()) {
    Node node = q.top();
    q.pop();
    if (vis[node.node]) {
      continue;
    }
    vis[node.node] = true;

    const vector<int>& link = link_edges[node.node];
    for (int i : link) {
      const Edge& edge = edges[i];
      int weight = node.d + edge.weight;
      if (weight < d[edge.to]) {
        d[edge.to] = weight;
        q.push({edge.to, weight});
      }
    }
  }
  double ans_rate, ans_dis;
  memset(checked, 0, sizeof(checked));
  dfs(0, 0, t, 1, ans_rate, ans_dis);

  printf("%.5lf %.5lf\n", ans_rate, ans_dis);
}

int main() {
  int test_case;
  cin >> test_case;
  for (int i = 1; i <= test_case; ++i) {
    sovle(i);
  }
  return 0;
}
