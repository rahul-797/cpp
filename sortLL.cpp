#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#define fr(s, e) for (int i = s; i < e; i++)
using namespace std;

struct Node {
  int data;
  struct Node* next;
};
typedef struct Node node;
typedef struct Node* link;

void print(link head) {
  if (head == NULL) return;
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

link createList(int* arr, int n) {
  if (n == 0) return NULL;
  link head;
  fr(0, n) {
    link temp = (link)malloc(sizeof(node));
    temp->data = arr[i];
    temp->next = NULL;
    if (i == 0)
      head = temp;
    else if (i == 1) {
      if (temp->data < head->data) {
        temp->next = head;
        head = temp;
      } else {
        head->next = temp;
      }
    } else {
      link prev = head, curr = head;
      while (curr != NULL) {
        if (temp->data < head->data) {
          temp->next = head;
          head = temp;
          break;
        } else if (temp->data < curr->data) {
          temp->next = curr;
          prev->next = temp;
          break;
        } else if (curr->next == NULL) {
          curr->next = temp;
          break;
        }
        prev = curr;
        curr = curr->next;
      }
    }
  }
  return head;
}

link merge(link head1, link head2) {
  if (head1 == NULL && head2 == NULL) return NULL;
  if (head1 == NULL && head2 != NULL) return head2;
  if (head2 == NULL && head1 != NULL) return head1;
  if (head1->data > head2->data) {
    link temp = head1;
    head1 = head2;
    head2 = temp;
  }
  link prev = head1, curr = head1->next;
  link next2 = head2->next;
  while (curr != NULL && head2 != NULL) {
    if (head2->data < curr->data) {
      head2->next = curr;
      prev->next = head2;
      prev = head2;
      head2 = next2;
      if (next2 == NULL) break;
      next2 = next2->next;
    } else {
      if (curr == NULL) break;
      prev = curr;
      curr = curr->next;
    }
  }
  if (curr == NULL) {
    prev->next = head2;
  }
  return head1;
}

int main() {
  int arr1[] = {2, 6, 4, 0, 8};
  int arr2[] = {1, 7, 3, 5, 9};
  link head1 = createList(arr1, sizeof(arr1) / sizeof(int));
  print(head1);
  link head2 = createList(arr2, sizeof(arr2) / sizeof(int));
  print(head2);
  link head = merge(head1, head2);
  print(head);
  cout << endl;
  return 0;
}
