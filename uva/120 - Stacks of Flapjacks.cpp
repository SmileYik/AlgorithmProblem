#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void reverse(vector<int>& vec, int b, int e) {
  int tmp;
  while (b < e) {
    tmp = vec[b];
    vec[b] = vec[e];
    vec[e] = tmp;
    ++b;
    --e;
  }
}

int main () {
  string line;
  vector<int> pancakes;
  vector<int> ans;
  int i, max, idx, size;
  while (getline(cin, line)) {
    pancakes.clear();
    ans.clear();
    stringstream ss(line);
    while (ss >> i) {
      pancakes.push_back(i);
    }
    size = pancakes.size();
    max = size;
    cout << line << "\n";

    while (max > 1 && !is_sorted(pancakes.begin(), pancakes.end())) {
      idx = 0;
      for (int j = 0; j < max; ++j) {
        if (pancakes[j] > pancakes[idx]) {
          idx = j;
        }
      }
      if (idx == max - 1) {
        --max;
        continue;
      }

      if (idx == 0) {
        --max;
        ans.push_back(size - max);
        reverse(pancakes, 0, max);
      } else {
        ans.push_back(size - idx);
        reverse(pancakes, 0, idx);
      }
    }
    for (int j : ans) {
      cout << j << " ";
    }
    cout << "0\n";
  }
}
