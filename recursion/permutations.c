#include <stdio.h>

void permutationGen(char *list, int i, int n) {
  int j, temp;

  if (i == n) {
    for (j = 0; j < n; j++) {
      printf("%c", list[j]);
    }
    printf("  ");
  } else {
    for (j = i; j < n; j++) {
      temp = list[i];
      list[i] = list[j];
      list[j] = temp;

      permutationGen(list, i + 1, n);

      temp = list[i];
      list[i] = list[j];
      list[j] = temp;
    }
  }
}

int main() {
  char list[] = {'a', 'b', 'c'};

  permutationGen(list, 0, 3);
}
