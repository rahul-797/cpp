#include <stdio.h>
#include <stdlib.h>

#define NIL 1000
#define DELETED 1001

void p(int *, int);

// Size of hash table is m
int m = 13;

int h(int, int);
int hash_insert(int *, int);
int hash_search(int *, int);
int hash_delete(int *, int);

// h1(k) = k mod m
// h2(k) = 1 + (k mod (m - 1))
int h1(int k) { return k % m; }

int h2(int k) { return 1 + (k % (m - 1)); }

int h(int k, int i) { return (h1(k) + i * h2(k)) % m; }

int hash_insert(int *T, int k) {
  int i = 0;
  int j;
  while (i < m) {
    j = h(k, i);
    if (T[j] == NIL || T[j] == DELETED) {
      T[j] = k;
      return j;
    }
    i++;
  }
  printf("Hash table overflow\n");
  return -1;
}

int hash_search(int *T, int k) {
  int i = 0;
  int j;
  while (i < m) {
    j = h(k, i);
    if (T[j] == NIL) return -1;
    if (T[j] == k) return j;
    i++;
  }
  return -1;
}

int hash_delete(int *T, int k) {
  int j = hash_search(T, k);
  if (j != -1) {
    T[j] = DELETED;
    return j;
  }
  return -1;
}

int main() {
  int *T = (int *)malloc(sizeof(int) * m);
  int i, k, x;
  for (i = 0; i < m; i++) T[i] = NIL;
  p(T, m);

  k = 79;
  printf("Inserting %d\n", k);
  hash_insert(T, k);
  k = 69;
  printf("Inserting %d\n", k);
  hash_insert(T, k);
  k = 72;
  printf("Inserting %d\n", k);
  hash_insert(T, k);
  k = 98;
  printf("Inserting %d\n", k);
  hash_insert(T, k);
  k = 14;
  printf("Inserting %d\n", k);
  hash_insert(T, k);
  k = 50;
  printf("Inserting %d\n", k);
  hash_insert(T, k);
  p(T, m);

  k = 98;
  printf("Deleting %d\n", k);
  hash_delete(T, k);
  p(T, m);

  k = 98;
  printf("Searching %d => ", k);
  x = hash_search(T, k);
  if (x == -1)
    printf("Not Found\n");
  else
    printf("Found at %d\n", x);

  k = 14;
  printf("Searching %d => ", k);
  x = hash_search(T, k);
  if (x == -1)
    printf("Not Found\n");
  else
    printf("Found at %d\n", x);

  free(T);
  return 0;
}

void p(int *T, int m) {
  int i;
  for (i = 0; i < m; i++) {
    if (T[i] == NIL)
      printf("%2d: NIL\n", i);
    else if (T[i] == DELETED)
      printf("%2d: DELETED\n", i);
    else
      printf("%2d: %d\n", i, T[i]);
  }
  printf("------------\n");
}
