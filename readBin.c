#include <stdio.h>

int main() {
  FILE* fp = fopen("input.bin", "rb");
  struct nums {
    int n1;
    int n2;
    int n3;
  } n;
  for (int i = 0; i < 5; i++) {
    fread(&n, sizeof(struct nums), 1, fp);
    printf("%d %d %d", n.n1, n.n2, n.n3);
    printf("\n");
  }
  fclose(fp);
  return 0;
}