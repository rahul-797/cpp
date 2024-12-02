#include <stdio.h>

int main() {
  FILE* fp = fopen("input.txt", "r");
  char ch;
  while ((ch = getc(fp)) != EOF) {
    putc(ch, stdout);
  }
  fclose(fp);
  return 0;
}
