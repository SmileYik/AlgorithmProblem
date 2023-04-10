#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;

/**
 * LIS:
 * A = A_1, A_2 ... A_n
 * f(i) is the longest increasing subsequence size of A_1 to A_i(include A_i)
 * f(i) = max{ f(1), f(2), ... , f(i - 1), 1 }
 * longest increasing subsequence size is max{ f(1), f(2), ..., f(n) }
 */


class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    int max_len = 0;
    vector<int> dp(size, 1);
    for (int i = 0; i < size; ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_len = max(max_len, dp[i]);
    }
    return max_len;
  }
};
