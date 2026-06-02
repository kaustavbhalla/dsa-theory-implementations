#include <stdio.h>

int hornersRule(int a[], int x_o, int n) {
  int result = 0;

  for (int i = 0; i < n; i++) {
    result = result * x_o + a[i];
  }

  return result;
}

int main() {
  int a[] = {3, -5, 2, 1};
  int x_o = 2;

  int ret = hornersRule(a, 2, 4);

  printf("%d\n", ret);
}
