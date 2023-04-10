#include <iostream>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
#define INF 0x0F0F0F0F
using namespace std;

class Edge {
public:
  int from, to;
  int weight;
  Edge() { }
  Edge(const int& _from, const int& _to, const int& _weight) : from(_from), to(_to), weight(_weight) { }
};

class MyNode {
public:
  int point;
  int value;

  MyNode() { }
  MyNode(const int& p, const int& v) : point(p), value(v) { }

  bool operator > (const MyNode& node) const {
    return value > node.value;
  }
};

class Dijkstra {
private:
  int edge_size = 0, statis_size = 0;
  unordered_map<int, int> status_point_map; // status integer(0~0xFFFFF) change to point_id.
  vector<Edge> edges;                       // edges
  vector<vector<int>> point_edges;          // point_id -> point's edge
public:
  void add_edge(int from_status, int to_status, int w) {
    edges.push_back({from_status, to_status, w});
    if (!status_point_map.count(from_status)) {
      status_point_map[from_status] = statis_size++;
    }
    if (!status_point_map.count(to_status)) {
      status_point_map[to_status] = statis_size++;
    }
    if (point_edges.size() < statis_size) {
      point_edges.resize(statis_size);
    }
    point_edges[status_point_map[from_status]].push_back(edge_size++);
  }

  int dijkstra(int from, int to) {
    if (!status_point_map.count(to) || !status_point_map.count(from)) {
      return -1;
    }
    from = status_point_map[from];
    to = status_point_map[to];
    vector<int> d(statis_size, INF);
    unordered_set<int> checked;
    d[from] = 0;
    priority_queue<MyNode, vector<MyNode>, greater<MyNode>> q;
    q.push({from, 0});

    while (!q.empty()) {
      MyNode node = q.top();
      q.pop();
      if (checked.count(node.point)) {
        continue;
      } else if (node.point == to) {
        break;
      }
      checked.insert(node.point);

      for (int i : point_edges[node.point]) {
        int j = status_point_map[edges[i].to];
        int tmp = d[node.point] + edges[i].weight;
        if (d[j] > tmp) {
          d[j] = tmp;
          q.push({j, tmp});
        }
      }
    }
    return d[to];
  }

};

// find shift;
int find_shift(const string& str, vector<int>& shift_lens) {
  int size = str.size();
  shift_lens.clear();
  int status = 0x00000000;
  // + is 0
  // - is 1
  for (int i = 0; i < size; ++i) {
    if (str[i] == '0') {
      shift_lens.push_back(size - i - 1);
    } else if (str[i] == '-') {
      status |= 1 << (size - i - 1);
    }
  }
  return status;
}

void find_all_status(int status, const vector<int>& shift_lens, int idx, Dijkstra& dijkstra, const vector<int>& to_shift_lens, int& to_default_status, int& value) {
  if (idx != shift_lens.size()) {
    find_all_status(status, shift_lens, idx + 1, dijkstra, to_shift_lens, to_default_status, value);
    find_all_status(status | (1 << shift_lens[idx]), shift_lens, idx + 1, dijkstra, to_shift_lens, to_default_status, value);
  } else {
    int default_to_status = to_default_status;
    for (int shift : to_shift_lens) {
      default_to_status |= ((status >> shift) & 0x1) << shift;
    }
    dijkstra.add_edge(status, default_to_status, value);
  }
}

bool sovle(int test_case) {
  int n, m;
  cin >> n >> m;
  if (!n && !m) {
    return false;
  }

  cout << "Product " << test_case << "\n";

  Dijkstra dijkstra;

  for (int i = 0; i < m; ++i) {
    int time;
    string from, to;
    cin >> time >> from >> to;
    vector<int> from_shift, to_shift, all_from_status;
    int default_from_status = find_shift(from, from_shift);
    int default_to_status = find_shift(to, to_shift);
    find_all_status(default_from_status, from_shift, 0, dijkstra, to_shift, default_to_status, time);
  }

  int result = dijkstra.dijkstra(0, (1 << n) - 1);
  if (result == -1 || result >= INF) {
    cout << "Bugs cannot be fixed.\n";
  } else {
    cout << "Fastest sequence takes " << result << " seconds.\n";
  }
  cout << "\n";
  return true;
}

int main() {
  int test_case = 1;
  while (sovle(test_case++));
  return 0;
}
