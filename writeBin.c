#include <stdio.h>

int main() {
  FILE* fp = fopen("input.bin", "wb");
  struct nums {
    int n1;
    int n2;
    int n3;
  } n;
  for (int i = 0; i < 5; i++) {
    n.n1 = i, n.n2 = i * 2, n.n3 = i * 3;
    fwrite(&n, sizeof(struct nums), 1, fp);
  }
  fclose(fp);
  return 0;
}
