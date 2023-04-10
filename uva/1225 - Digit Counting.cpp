#include <iostream>
using namespace std;

void count_num(int* amount, int n) {
  while (n != 0) {
    ++amount[n % 10];
    n /= 10;

  }
}

void count(int n) {
  int amount[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 1; i <= n; ++i) {
    count_num(amount, i);
  }
  for (int i = 0; i < 9; ++i) {
    cout << amount[i] << " ";
  }
  cout << amount[9] << "\n";
}

int main() {
  int n;
  cin >> n;
  int a;
  while (n > 0) {
    --n;
    cin >> a;
    count(a);
  }


  return 0;
}
