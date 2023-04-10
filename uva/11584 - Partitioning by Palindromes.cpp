#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
typedef long long ll;
using namespace std;

bool palindrome[1005][1005];
int ans[1005];

int partition(string s) {
  memset(palindrome, false, sizeof(palindrome));
  int size = s.length();
  for (int i = 0; i < size; ++i) {
    int left = i;
    int right = i;
    palindrome[left][right] = true;
    // same charactor
    while (right < size - 1 && s[right + 1] == s[left]) {
      ++right;
      palindrome[left][right] = true;
    }
    while (left > 0 && s[left - 1] == s[right]) {
      --left;
      palindrome[left][right] = true;
    }
    while (left > 0 && right < size - 1 && s[left - 1] == s[right + 1]) {
      --left;
      ++right;
      palindrome[left][right] = true;
    }
  }

  memset(ans, 0x70, sizeof(ans));
  ans[0] = 0;
  for (int i = 1; i <= size; ++i) {
    ans[i] = ans[i - 1] + 1;
    for (int j = 1; j < i; ++j) {
      if (palindrome[j - 1][i - 1]) {
        ans[i] = min((ans[j - 1] + 1), ans[i]);
      }
    }
  }

  return ans[size];
}

int main() {
  int n;
  string s;
  cin >> n;
  while (n--) {
    cin >> s;
    cout << partition(s) << endl;
  }
  return 0;
}
