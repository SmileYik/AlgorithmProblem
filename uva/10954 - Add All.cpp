#include <functional>
#include <iostream>
#include <queue>
using namespace std;

bool sovle() {
  priority_queue<int, vector<int>, greater<int>> q;
  int n;
  cin >> n;
  if (n == 0) {
    return false;
  }
  int num;
  while (n--) {
    cin >> num;
    q.push(num);
  }
  int sum = 0;
  while (q.size() != 1) {
    // cout << q.top() << "+";
    num = q.top();
    q.pop();
    // cout << q.top() << " ";
    num += q.top();
    q.pop();
    sum += num;
    q.push(num);
  }
  cout << sum << "\n";
  return true;
}

int main() {
  while (sovle()) {}
  return 0;
}
