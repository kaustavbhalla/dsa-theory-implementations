#include <stdio.h>

int main() {
  int r1, c1;
  int r2, c2;

  scanf("%d %d", &r1, &c1);
  scanf("%d %d", &r2, &c2);

  if (c1 != r2) {
    printf("Matrix multiplication not possible!");
    return 0;
  }

  int m1[r1][c1];
  int m2[r2][c2];

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c1; j++) {
      printf("Enter element (%d, %d): ", i, j);
      scanf("%d", &m1[i][j]);
    }
  }

  for (int i = 0; i < r2; i++) {
    for (int j = 0; j < c2; j++) {
      printf("Enter element (%d, %d): ", i, j);
      scanf("%d", &m2[i][j]);
    }
  }

  int m3[r1][c2];

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      m3[i][j] = 0;
    }
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      for (int k = 0; k < r2; k++) {
        m3[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }

  for (int i = 0; i < r1; i++) {
    for (int j = 0; j < c2; j++) {
      printf("%d ", m3[i][j]);
    }
    printf("\n");
  }
}
