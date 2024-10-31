#include <stdio.h>
#include <stdlib.h>
#define n 9

struct Node {
  int data;
  struct Node* next;
};

typedef struct Node node;
typedef struct Node* link;

int insert(node** head, int data) {
  node* temp = (node*)malloc(sizeof(node));
  temp->data = data;
  temp->next = NULL;

  if (*head == NULL) {
    *head = temp;
    return 0;
  }

  temp->next = *head;
  *head = temp;
  return 0;
}

int delete(node** head) {
  node* temp = *head;
  *head = (*head)->next;
  free(temp);
  return 0;
}

int isEmpty(node** st) { return *st == NULL; }

void push(node** st, int data) {
  if (insert(st, data)) printf("stack Overflow!\n");
}

int peek(node** st) {
  if (!isEmpty(st))
    return (*st)->data;
  else
    return -1;
}

int pop(node** st) {
  if (isEmpty(st)) {
    printf("stack Underflow\n");
    return -1;
  }
  int temp = peek(st);
  delete (st);
  return temp;
}

int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int b[n] = {};
int c[n] = {};
int aIndex = 0;
int bIndex = 0;
link s = NULL;

void aPop() {
  int temp = a[aIndex];
  a[aIndex] = 0;
  aIndex++;
  push(&s, temp);
}

void bPush() {
  int top = pop(&s);
  b[bIndex] = top;
  bIndex++;
}

int main() {
  printf("Enter the permutation of 1 to %d:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i]);
  }

  int cIndex = 0;
  while (cIndex != n - 1) {
    if (peek(&s) == -1 || peek(&s) < c[cIndex]) {
      aPop();
    } else if (peek(&s) == c[cIndex]) {
      bPush();
      cIndex++;
    } else {
      printf("Sequence is not stack generatable");
      exit(0);
    }
  }
  printf("Sequence is stack generatable");
  return 0;
}
