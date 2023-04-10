#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Node {
public:
  Node* left;
  Node* right;
  int val;
  int sum = 0;
};

bool read_line(vector<int>& vec) {
  vec.clear();
  string line;
  if (!getline(cin, line)) {
    return false;
  }
  stringstream ss(line);
  int p;
  while (ss >> p) {
    vec.push_back(p);
  }
  return true;
}

Node* build_tree(vector<int>& in_order, vector<int>& post_order, int i_l, int i_r, int p_l, int p_r) {
  if (i_l > i_r) {
    return NULL;
  }
  Node* node = new Node();
  node->val = post_order[p_r];
  auto target = find(in_order.begin() + i_l, in_order.begin() + i_r + 1, node->val);
  int left_size = target - in_order.begin() - i_l;
  int right_size = in_order.begin() + i_r - target;
  node->left = build_tree(in_order, post_order, i_l, i_l + left_size - 1, p_l, p_l + left_size - 1);
  node->right = build_tree(in_order, post_order, i_l + left_size + 1, i_r, p_l + left_size, p_r - 1);
  return node;
}

int find_best_sum(Node* node) {
  queue<Node*> que;
  que.push(node);
  int step = 1;
  int next_step = 0;
  int best = 1 << 30, best_sum = 1 << 30;
  while (!que.empty()) {
    node = que.front();
    que.pop();
    --step;
    bool flag = true;
    int sum = node->val + node->sum;
    if (node->left != NULL) {
      node->left->sum = sum;
      ++next_step;
      que.push(node->left);
      flag = false;
    }
    if (node->right != NULL) {
      node->right->sum = sum;
      que.push(node->right);
      ++next_step;
      flag = false;
    }
    if (flag && (best_sum > sum || (best_sum == sum && best > node->val))) {
      best_sum = sum;
      best = node->val;
    }
    if (!step) {
      step = next_step;
      next_step = 0;
    }
  }
  return best;
}

int main() {
  Node* root;
  vector<int> in_order;
  vector<int> post_order;
  while (read_line(in_order)) {
    read_line(post_order);
    root = build_tree(in_order, post_order, 0, in_order.size() - 1, 0, post_order.size() - 1);
    cout << find_best_sum(root) << "\n";
  }

  return 0;
}
