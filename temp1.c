#include <stdio.h>
#include <stdlib.h>

int main() {
  /* int(*arr)[2][2] = malloc(sizeof(*arr)); */
  int(*arr)[3] = malloc(sizeof(int) * 6);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      arr[i][j] = i + j;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
