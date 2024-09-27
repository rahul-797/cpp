#include <stdio.h>

int main() {
  int arr[3] = {1, 2, 3};
  printf("%p\n", arr);
  printf("%p\n", arr + 1);
  printf("%p\n", &arr);
  printf("%p\n", &arr + 1);
  return 0;
}
