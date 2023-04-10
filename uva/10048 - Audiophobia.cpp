#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define INF 0x0F0F0F0F
using namespace std;



class Edge {
public:
  int from, to, weight;
  Edge() { }
  Edge(int _from, int _to, int _weight) : from(_from), to(_to), weight(_weight) { }
};

class MyNode {
public:
  int key;
  int value;

  bool operator > (const MyNode& other) const {
    return value > other.value;
  }
};

class Dijkstra {
private:
  int point_size, edge_size = 0;
  vector<Edge> edges;
  vector<vector<int>> point_to;
  vector<int> d;
public:
  Dijkstra(int p_size) : point_size(p_size) {
    point_to.resize(p_size + 1);
    d.resize(p_size + 1);
  }

  void add_edge(int from, int to, int weight) {
    edges.push_back(Edge(from, to, weight));
    point_to[from].push_back(edge_size++);
  }

  void dijkstra(int start) {
    // init
    bool visite[point_size + 1];
    memset(visite, false, sizeof(visite));
    for (int i = 1; i <= point_size; ++i) {
      d[i] = INF;
    }
    d[start] = 0;
    priority_queue<MyNode, vector<MyNode>, greater<MyNode>> q;
    q.push({start, 0});
    while (!q.empty()) {
      MyNode node = q.top();
      q.pop();

      if (visite[node.key]) {
        continue;
      }
      visite[node.key] = true;

      for (int j : point_to[node.key]) {
        int greater = max(edges[j].weight, d[node.key]);
        if (greater < d[edges[j].to]) {
          d[edges[j].to] = greater;
          q.push({edges[j].to, greater});
        }
      }
    }

  }

  int get_distance(int to) {
    return d[to];
  }

};

bool sovle(int test_case) {
  int c, s, q;
  cin >> c >> s >> q;
  if (!c && !s && !q) {
    return false;
  }
  if (test_case != 1) {
    cout << "\n";
  }
  cout << "Case #" << test_case << "\n";

  Dijkstra dijkstra(c);

  int x, y, m;
  for (int i = 0; i < s; ++i) {
    cin >> x >> y >> m;
    dijkstra.add_edge(x, y, m);
    dijkstra.add_edge(y, x, m);
  }

  int last_x = -1;
  for (int i = 0; i < q; ++i) {
    cin >> x >> y;
    if (last_x != x) {
      dijkstra.dijkstra(x);
      last_x = x;
    }
    int d = dijkstra.get_distance(y);
    if (d == INF) {
      cout << "no path\n";
    } else {
      cout << d << "\n";
    }
  }

  return true;
}


int main() {
  int test_case = 1;
  while (sovle(test_case++));
  return 0;
}
