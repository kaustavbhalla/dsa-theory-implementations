#include <stdbool.h>
#include <stdio.h>

void genPerm(bool a[], int i, int n) {
  int j, temp;
  if (i == n) {
    for (j = 0; j < n; j++) {
      printf("%d", a[j]);
    }

    printf("  ");
  } else {
    for (j = i; j < n; j++) {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;

      genPerm(a, i + 1, n);

      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
}

int main() {}
