#include <stdio.h>
#include <stdlib.h>

int main() {
  int r1, c1;
  int r2, c2;

  scanf("%d %d", &r1, &c1);
  scanf("%d %d", &r2, &c2);

  int m1[r1][c1];
  int m2[r2][c2];

  if ((r1 == r2) && (c1 == c2)) {
    int m3[r1][c1];

    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c1; j++) {
        m3[i][j] = m1[i][j] + m2[i][j];
      }
    }
  }
}
