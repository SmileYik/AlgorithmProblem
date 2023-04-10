#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;
int main() {
  return 0;
}

/**
 * LCS:
 * A = A_1, A_2 ... A_n
 * B = B_1, B_2 ... B_n
 * f(i, j) is A_1 ~ A_i and B_1 ~ B_j longest common subsequence
 * f(i, j) =
 *            f(i - 1, j - 1) + 1,            if A_i = B_i
 *            max{f(i - 1, j), f(i, j - 1)},  other
 */

class Solution1 {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int size1 = text1.size();
    int size2 = text2.size();
    // dp[text1_idx][text2_idx] = text1_idx ~ text2_idx common sub length
    vector<vector<int>> dp(size1, vector<int>(size2, 0));
    for (int i = 0; i < size1; ++i) {
      for (int j = 0; j < size2; ++j) {
        if (text1[i] == text2[j]) {
          if (i == 0 || j == 0) {
            if (i == 0 && j == 0) {
              dp[i][j] = 1;
            } else if (i == 0) {
              dp[i][j] = max(1, dp[i][j - 1]);
            } else {
              dp[i][j] = max(1, dp[i - 1][j]);
            }
          } else {
            dp[i][j] = dp[i - 1][j - 1] + 1;
          }
        } else if (i != 0 && j != 0) {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        } else if (i != 0 && j == 0) {
          dp[i][j] = dp[i - 1][j];
        } else if (i == 0 && j != 0) {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }
    return dp[size1 - 1][size2 - 1];
  }
};
class Solution2 {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int size1 = text1.size();
    int size2 = text2.size();
    // dp[text1_idx][text2_idx] = text1_idx ~ text2_idx common sub length
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (int i = 0; i < size1; ++i) {
      for (int j = 0; j < size2; ++j) {
        if (text1[i] == text2[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }
    return dp[size1][size2];
  }
};
