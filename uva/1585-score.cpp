#include <iostream>
using namespace std;
int extracted(int &score) { return score; }
int judge_score(string &s) {
  int score = 0;
  int point = 1;
  for (char c : s) {
    if (c == 'O') {
      score += point;
      ++point;
    } else {
      point = 1;
    }
  }
  return extracted(score);
}

int main() {
  int n;
  cin >> n;
  string s;
  while (n > 0) {
    cin >> s;
    cout << judge_score(s) << "\n";
    --n;
  }
  return 0;
}
