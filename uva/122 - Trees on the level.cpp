#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

class Node {
public:
  Node* left = NULL;
  Node* right = NULL;
  bool used = false;
  int val;
};

void get_tree_node(const string& node, int* val, string& position) {
  int i = 0;
  while (node[i++] != ',') { }
  sscanf(node.substr(1, i - 2).c_str(), "%d", val);
  position = node.substr(i, node.length() - i - 1);
}

bool is_valid_tree(Node* node) {
  if (node == NULL) {
    return true;
  }
  if (!node->used && (node->left != NULL || node->right != NULL)) {
    return false;
  }
  return is_valid_tree(node->left) && is_valid_tree(node->right);
}

int main() {
  string line;
  int val;
  string position;
  Node* root = NULL;
  bool is_failed = false;
  while (cin >> line) {
    if (line == "()") {
      if (!is_failed) {
        vector<int> vec;
        if (root != NULL && root->used) {
          queue<Node*> que;
          que.push(root);
          Node* node;
          while (!que.empty()) {
            node = que.front();
            que.pop();
            if (!node->used && (node->left != NULL || node->right != NULL)) {
              is_failed = true;
              delete node;
              break;
            }
            vec.push_back(node->val);
            if (node->left != NULL) {
              que.push(node->left);
            }
            if (node->right != NULL) {
              que.push(node->right);
            }
            delete node;
          }
          if (!is_failed) {
            int size = vec.size() - 1;
            for (int i = 0; i <= size; ++i) {
              cout << vec[i];
              if (i != size) {
                cout << " ";
              } else {
                cout << "\n";
              }
            }
          }
        } else {
          is_failed = true;
        }
      }
      if (is_failed) {
        cout << "not complete\n";
      }
      is_failed = false;
      root = NULL;
    } else {
      if (is_failed) {
        continue;
      }
      get_tree_node(line, &val, position);
      if (root == NULL) {
        root = new Node();
      }
      Node* node = root;
      for (char c : position) {
        if (c == 'L') {
          if (node->left == NULL) {
            node->left = new Node();
          }
          node = node->left;
        } else if (c == 'R') {
          if (node->right == NULL) {
            node->right = new Node();
          }
          node = node->right;
        } else {
          is_failed = true;
          break;
        }
      }
      if (is_failed || node->used) {
        is_failed = true;
        continue;
      }
      node->used = true;
      node->val = val;
    }
  }

  return 0;
}
