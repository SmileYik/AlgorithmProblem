#include <iostream>
#include <cstdlib>
using namespace std;

bool maxsum(int* A, int start, int end, int& l, int& r, int& sum) {
  if (start > end) {
    l = 0;
    r = -1;
    return false;
  } else if (start == end - 1) {
    l = start;
    r = end;
    sum = A[l];
    return true;
  } else {
    int mid = start + ((end - start) >> 1);
    int left_l, left_r, left_sum, right_l, right_r, right_sum;
    bool left_flag = maxsum(A, start, mid, left_l, left_r, left_sum);
    bool right_flag = maxsum(A, mid, end, right_l, right_r, right_sum);

    int max_left = A[mid - 1], max_right = A[mid];
    sum = 0;
    l = mid - 1;
    r = mid;
    for (int i = mid - 1; i >= start; --i) {
      sum += A[i];
      if (max_left < sum) {
        l = i;
        max_left = sum;
      }
    }
    sum = 0;
    for (int i = mid; i < end; ++i) {
      sum += A[i];
      if (max_right < sum) {
        r = i;
        max_right = sum;
      }
    }
    sum = max_left + max_right;
    if (sum > left_sum && sum > right_sum) {
      // ignore
    } else if (left_sum > right_sum) {
      l = left_l;
      r = left_r;
      sum = left_sum;
    } else {
      l = right_l;
      r = right_r;
      sum = right_sum;
    }
    return true;
  }
}


int main() {
  int n;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  int l, r, sum;
  maxsum(A, 0, n, l, r, sum);
  cout << l << " " << r << " " << sum << endl;
}
