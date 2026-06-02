#include <stdbool.h>
#include <stdio.h>
void swap(bool *a, bool *b) {
  bool temp = *a;
  *a = *b;
  *b = temp;
}

void boolRec(bool list[], int i, int n) {
  int j, temp;

  if (i == n) {
    for (j = 0; j <= n; j++) {
      printf("%b", list[j]);
    }
    printf(" ");
  } else {
    for (j = i; j <= n; j++) {
      swap(&list[i], &list[j]);
      boolRec(list, i + 1, n);
      swap(&list[i], &list[j]);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
}
