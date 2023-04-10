#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double mass(char c) {
  switch (c) {
    case 'C':
      return 12.01;
    case 'H':
      return 1.008;
    case 'O':
      return 16.00;
    case 'N':
      return 14.01;
  }
  return 0;
}

double molar_mass(string& s) {
  int length = 0;
  char pre_c = '\0';
  double sum = 0;
  for (char c : s) {
    if (pre_c == '\0') {
      pre_c = c;
      continue;
    }
    double m = mass(c);
    if (m == 0) {
      length *= 10;
      length += c - '0';
    } else {
      sum += max(1, length) * mass(pre_c);
      pre_c = c;
      length = 0;
    }
  }
  return sum + max(1, length) * mass(pre_c);
}

int main() {
  int n;
  cin >> n;
  string s;
  while (n > 0) {
    --n;
    cin >> s;
    printf("%.3lf\n", molar_mass(s));
  }
  return 0;
}
