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

void print(link head) {
  if (head == NULL) return;
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  int arr1[] = {2, 6, 4, 0, 8};
  int arr2[] = {3, 9, 1, 7, 5};
  link head1 = createList(arr1, sizeof(arr1) / sizeof(int));
  print(head1);
  link head2 = createList(arr2, sizeof(arr2) / sizeof(int));
  print(head2);
  cout << endl;
  return 0;
}
