#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool sovle() {
  int n;
  if (!(cin >> n)) {
    return false;
  }
  int a, b;
  stack<int> s;
  queue<int> q;
  priority_queue<int, vector<int>, less<int>> pql;
  priority_queue<int, vector<int>, greater<int>> pqg;
  bool flag_s = true;
  bool flag_q = true;
  bool flag_pql = true;
  bool flag_pqg = true;
  while (n--) {
    cin >> a >> b;
    if (a == 1) {
      if (flag_s) {
        s.push(b);
      }
      if (flag_q) {
        q.push(b);
      }
      if (flag_pqg) {
        pqg.push(b);
      }
      if (flag_pql) {
        pql.push(b);
      }
    } else if (a == 2) {
      if (flag_s) {
        if (!s.empty() && s.top() == b) {
          s.pop();
        } else {
          flag_s = false;
        }
      }
      if (flag_q) {
        if (!q.empty() && q.front() == b) {
          q.pop();
        } else {
          flag_q = false;
        }
      }
      if (flag_pqg) {
        if (!pqg.empty() && pqg.top() == b) {
          pqg.pop();
        } else {
          flag_pqg = false;
        }
      }
      if (flag_pql) {
        if (!pql.empty() && pql.top() == b) {
          pql.pop();
        } else {
          flag_pql = false;
        }
      }
    }
  }
  int flags[2] = {0, 0};
  flags[flag_s]++;
  flags[flag_pql]++;
  // flags[flag_pql]++;
  flags[flag_q]++;
  // cout << flags[1] << endl;
  if (flags[1] == 1) {
    if (flag_s) {
      cout << "stack\n";
    } else if (flag_q) {
      cout << "queue\n";
    } else {
      cout << "priority queue\n";
    }
  } else if (flags[1] == 0) {
    cout << "impossible\n";
  } else {
    cout << "not sure\n";
  }
  return true;
}

int main() {
  while (sovle());
  return 0;
}
