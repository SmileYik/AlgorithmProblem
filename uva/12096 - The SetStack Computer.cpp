#include <iostream>
#include <set>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

class MyStack {
private:
  typedef set<int> Set;
  typedef stack<Set> Stack;
  typedef map<Set, int> SetIdCache;

  Stack s;
  SetIdCache id_cache;
  unsigned long long idx = 0;

public:
  int Push() {
    Set new_set;
    s.push(new_set);
    return 0;
  }

  int Dup() {
    s.push(s.top());
    return s.top().size();
  }

  int Union() {
    Set s1 = s.top();
    s.pop();
    Set s2 = s.top();
    s.pop();
    Set new_one;
    set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(new_one, new_one.begin()));
    s.push(new_one);
    if (!id_cache.count(new_one)) {
      id_cache[new_one] = idx++;
    }
    return new_one.size();
  }

  int Intersect() {
    Set s1 = s.top();
    s.pop();
    Set s2 = s.top();
    s.pop();
    Set new_one;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(new_one, new_one.begin()));
    if (!id_cache.count(new_one)) {
      id_cache[new_one] = idx++;
    }
    s.push(new_one);
    return new_one.size();
  }

  int Add() {
    Set s1 = s.top();
    s.pop();
    Set s2 = s.top();
    s.pop();
    if (!id_cache.count(s1)) {
      id_cache[s1] = idx++;
    }
    s2.insert(id_cache[s1]);
    s.push(s2);
    return s2.size();
  }
};

void round() {
  int n;
  cin >> n;
  string cmd;
  MyStack my_stack;
  while (n--) {
    cin >> cmd;
    switch (cmd[0]) {
      case 'P':
        cout << my_stack.Push() << endl;
        break;
      case 'D':
        cout << my_stack.Dup() << endl;
        break;
      case 'A':
        cout << my_stack.Add() << endl;
        break;
      case 'U':
        cout << my_stack.Union() << endl;
        break;
      case 'I':
        cout << my_stack.Intersect() << endl;
        break;
    }
  }
  cout << "***\n";
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    round();
  }
  return 0;
}
