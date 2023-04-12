#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

struct Edge {
  int from, to, weight;
  bool operator>(const Edge& e) const {
    return weight > e.weight;
  }
};

vector<Edge> edges;
vector<vector<int>> link_edges;

int distance(int a, int b, int node_size) {
  priority_queue<Edge, vector<Edge>, greater<Edge>> p;
  bool vis[2][node_size + 1];
  int d[2][node_size + 1];
  memset(d, 0x07, sizeof(d));
  memset(vis, false, sizeof(vis));
  p.push({a, 0, 0});
  d[0][a] = 0;
  while (!p.empty()) {
    Edge node = p.top();
    p.pop();
    if (vis[node.to][node.from]) {
      continue;
    }
    vis[node.to][node.from] = true;
    for (int i : link_edges[node.from]) {
      Edge e = edges[i];
      if (e.weight + node.weight < d[!node.to][e.to]) {
        d[!node.to][e.to] = e.weight + node.weight;
        p.push({e.to, !node.to, d[!node.to][e.to]});
      }
    }
  }
  return d[0][b];
}

bool sovle() {
  int C, V;
  if (!(cin >> C >> V)) {
    return false;
  }
  edges.clear();
  link_edges.clear();
  link_edges.resize(C + 1);
  int a, b, c;
  for (int i = 0; i < V; ++i) {
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
    link_edges[a].push_back(edges.size() - 1);
    edges.push_back({b, a, c});
    link_edges[b].push_back(edges.size() - 1);
  }
  int lowest_cost = distance(1, C, C);
  cout << (lowest_cost == 0x07070707 ? -1 : lowest_cost) << endl;
  return true;
}

int main() {
  while (sovle());
  return 0;
}
