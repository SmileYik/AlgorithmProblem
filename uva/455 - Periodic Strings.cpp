#include <iostream>
using namespace std;

bool is_match(string& s1, string& s2) {
  string s = s2;
  while (s.length() < s1.length()) {
    s += s2;
  }
  return s == s1;
}

int min_loop(string& s) {
  string a = "";
  for (char c : s) {
    if (a.length() != 0) {
      if (a[0] == c) {
        if (is_match(s, a)) {
          return a.length();
        }
      }
    }
    a += c;
  }
  return s.length();
}

int main() {
  int n;
  cin >> n;
  string s;
  while (n > 0) {
    --n;
    cin >> s;
    cout << min_loop(s) << "\n";
    if (n) {
      cout << "\n";
    }
  }
  return 0;
}
