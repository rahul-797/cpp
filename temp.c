#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int(*p)[3];
  p = &arr[0];

  int *i = NULL;
  i = (int *)malloc(sizeof(int));
  i = NULL;
  printf("%p", i);
  return 0;
}
