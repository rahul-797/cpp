#include <stdio.h>
#include <time.h>

void function_to_measure() {
  for (long i = 0; i < 1000000000; i++) {
    long j = 1l;
    j = i * j;
  }
}

int main() {
  clock_t start, end;
  double cpu_time_used;

  start = clock();
  function_to_measure();
  end = clock();

  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Execution time: %f seconds\n", cpu_time_used);

  return 0;
}
