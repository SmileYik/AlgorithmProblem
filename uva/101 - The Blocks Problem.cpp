#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void clear_block(vector<vector<int>>& blocks, int b) {
  for (int i = 0; i < blocks[b].size(); ++i) {
    int now = blocks[b][i];
    if (now == b) {
      continue;
    }
    blocks[now].push_back(now);
  }
  blocks[b].clear();
  blocks[b].push_back(b);
}

void pile_onto(vector<vector<int>>& blocks, int a, int b) {
  clear_block(blocks, b);
  blocks[b] = blocks[a];
  blocks[a] = vector<int>();
}

void pile_over(vector<vector<int>>& blocks, int a, int b) {
  for (int i : blocks[a]) {
    blocks[b].push_back(i);
  }
  blocks[a].clear();
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> blocks(n, vector<int>());
  for (int i = 0; i < n; ++i) {
    blocks[i].push_back(i);
  }
  string cmd1, cmd2;
  int b1, b2;
  while (cin >> cmd1 && cmd1 != "quit") {
    cin >> b1 >> cmd2 >> b2;
    if (b1 == b2) {
      continue;
    } else if (cmd1 == "move") {
      if (cmd2 == "onto") {
        clear_block(blocks, b1);
        clear_block(blocks, b2);
        pile_over(blocks, b1, b2);
      } else {
        clear_block(blocks, b1);
        pile_over(blocks, b1, b2);
      }
    } else if (cmd2 == "onto") {
      pile_onto(blocks, b1, b2);
    } else {
      pile_over(blocks, b1, b2);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d:", i);
    for (int j : blocks[i]) {
      printf(" %d", j);
    }
    printf("\n");
  }
  return 0;
}
