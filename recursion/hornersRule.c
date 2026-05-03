#include <stdio.h>

int hornersRule(int a[], int xo, int n) {
  int result = a[0];

  for (int i = 1; i < n; i++) {
    result = result * xo + a[i];
  }

  return result;
}

int main() {
  int a[] = {2, -6, 2, -1};
  int xo = 3;
  int n = sizeof(a) / sizeof(int);
  int retV = hornersRule(a, xo, n);

  printf("%d\n", retV);
}
