#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int main() {
  int l;
  scanf("%d", &l);
  int d, i;
  while (l--) {
    scanf("%d%d", &d, &i);
    int last_step_first_id = (1 << (d - 1));
    int max_id = (1 << d) - 1;
    int id = 1;
    while (id < last_step_first_id) {
      if ((i & 0x1) == 0) {
        id = (id << 1) + 1;
        i >>= 1;
      } else {
        id <<= 1;
        i = (i + 1) >> 1;
      }
    }
    printf("%d\n", id);
  }
  scanf("%d", &d);
  return 0;
}
/*
 * Test Case 1:
5
4 2
3 4
10 1
2 2
8 128
-1
Test Case 2
34
20 357219
16 14792
18 62856
6 3
6 27
19 196169
3 1
18 88949
13 916
16 13711
14 5895
18 98280
9 145
15 6927
17 60239
17 28939
7 26
9 163
14 1580
13 2783
18 73685
6 7
2 1
4 2
5 6
16 2022
19 146902
10 253
16 11007
9 142
10 330
4 7
16 2215
3 3
-1
 */
