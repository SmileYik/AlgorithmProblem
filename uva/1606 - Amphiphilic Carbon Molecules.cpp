#include <iostream>
#include <vector>
#include <map>
using namespace std;

int sovle() {
  map<int, map<int, int>> points;
  int n, x, y, z;
  cin >> n;
  while (n--) {
    if (!points.count(x)) {
      points[x] = map<int, int>();
    }
    points[x][y] = z;
  }

}

int main() {
  return 0;
}
