#include <iostream>
using namespace std;
string contries = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int submain () {
  int n;
  if (!(cin >> n)) {
    return 0;
  }
  int idx = 0;
  cout << 2 << " " << n << " " << n << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << contries[i];
    }
    cout << "\n";
  }
  cout << "\n";
  for (int i = 0; i < n; ++i) {
    idx++;
    for (int j = 0; j < n; ++j) {
      cout << contries[j];
    }
    cout << "\n";
  }
  return 1;
}

int main() {
  while (submain());
}
