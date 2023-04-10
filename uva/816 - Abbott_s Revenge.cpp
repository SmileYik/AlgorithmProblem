#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

class Point {
public:
  int x;
  int y;
  char dir;
  unsigned int prev = 0;
};

map<char, int> sign;
const int N = 1;
const int E = 2;
const int W = 0;
const int S = 3;
const string COMPASS = "WNES";

const int L = 0;
const int R = 1;
const int F = 2;
const string TURNS = "LRF";

// [x][y][dir][turn]
bool flag[85][85][4][3];
bool checked[85][85][4][3];

unsigned int memory_idx = 1;
vector<Point> memory;

Point* get_point(int idx) {
  return &memory[idx - 1];
}

unsigned int join_memory(Point p) {
  memory.push_back(p);
  return memory_idx++;
}

char fun_turn(char ori, char turn) {
  // printf("  %c + %c -> ", ori, turn);
  if (turn == 'F') {
    // printf("%c\n", ori);
    return ori;
  } else {
    int i = sign[ori];
    if (turn == 'L') {
      --i;
    } else {
      ++i;
    }
    // printf("%c(%d)\n", COMPASS[(i + 4) % 4], i);
    return COMPASS[(i + 4) % 4];
  }
}

bool do_sovle() {
  memset(flag, false, sizeof(flag));
  memset(checked, false, sizeof(checked));
  memory.clear();
  memory_idx = 1;

  string title;
  cin >> title;
  if (title == "END") {
    return false;
  }
  Point in, out;
  cin >> in.x >> in.y >> in.dir >> out.x >> out.y;
  int x, y;
  string str;
  while (cin >> x && x != 0) {
    cin >> y;
    while (cin >> str && str != "*") {
      // printf("%s", str.c_str());
      int size = str.length();
      while (--size) {
        // printf("(%d, %d) %c %c\n", x, y, str[0], str[size]);
        flag[x][y][sign[str[0]]][sign[str[size]]] = true;
      }
    }
  }

  queue<Point> que;
  que.push(in);
  while (!que.empty()) {
    in = que.front();
    int ptr = join_memory(in);
    que.pop();

    x = in.x;
    y = in.y;
    if (in.dir == 'N') {
      --x;
    } else if (in.dir == 'E') {
      ++y;
    } else if (in.dir == 'W') {
      --y;
    } else {
      ++x;
    }

    if (x == out.x && y == out.y) {
      cout << title;
      vector<int> vec;
      while (ptr != 0) {
        // cout << ptr << " ";
        vec.push_back(ptr);
        ptr = get_point(ptr)->prev;
      }
      int return_line = 0;
      while (!vec.empty()) {
        ptr = vec.back();
        in = *get_point(ptr);
        vec.pop_back();
        if (return_line++ % 10 == 0) {
          printf("\n ");
        }
        printf(" (%d,%d)", in.x, in.y);
      }
      if (return_line++ % 10 != 0) {
        printf(" (%d,%d)\n", x, y);
      } else {
        printf("\n  (%d,%d)\n", x, y);
      }
      return true;
    }

    // printf("(%d, %d, %c) -> (%d, %d)\n", in.x, in.y, in.dir, x, y);
    for (char turn : TURNS) {
      if (!checked[x][y][sign[in.dir]][sign[turn]] && flag[x][y][sign[in.dir]][sign[turn]]) {
        checked[x][y][sign[in.dir]][sign[turn]] = true;
        Point p;
        p.x = x;
        p.y = y;
        p.dir = fun_turn(in.dir, turn);
        p.prev = ptr;
        que.push(p);
        // printf("  (%d, %d, %c) -> (%d, %d, %c)\n", in.x, in.y, in.dir, x, y, p.dir);
      }
    }
  }
  cout << title << "\n  No Solution Possible\n";
  return true;
}

int main() {
  sign['N'] = N;
  sign['E'] = E;
  sign['W'] = W;
  sign['S'] = S;
  sign['L'] = L;
  sign['R'] = R;
  sign['F'] = F;
  while (do_sovle()) { }
  return 0;
}
