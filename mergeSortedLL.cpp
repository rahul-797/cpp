#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

Node* insertEnd(Node*& head, int val) {
  Node* node = new Node(val);
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
  return node;
}

void print(Node*& head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

Node* mergeLL(Node*& head1, Node*& head2) {
  Node* newHead = NULL;
  Node* node1 = head1;
  Node* node2 = head2;
  Node* next1 = node1->next;
  Node* next2 = node2->next;
  Node* last = NULL;
  Node* leftOut = NULL;
  if (head1->data <= head2->data) {
    newHead = head1;
    node1 = next1;
    next1 = next1->next;
  } else {
    newHead = head2;
    node2 = next2;
    next2 = next2->next;
  }
  last = newHead;
  while (node1 != NULL && node2 != NULL) {
    if (node1->data <= node2->data) {
      last->next = node1;
      last = node1;
      node1 = next1;
      if (node1 == NULL) leftOut = node2;
      if (next1 != NULL) next1 = next1->next;

    } else {
      last->next = node2;
      last = node2;
      node2 = next2;
      if (node2 == NULL) leftOut = node1;
      if (next2 != NULL) next2 = next2->next;
    }
  }
  last->next = leftOut;
  return newHead;
}

int main() {
  Node* head = new Node(2);
  insertEnd(head, 3);
  insertEnd(head, 5);
  insertEnd(head, 6);
  insertEnd(head, 9);
  print(head);

  Node* head2 = new Node(1);
  insertEnd(head2, 2);
  insertEnd(head2, 2);
  insertEnd(head2, 4);
  insertEnd(head2, 6);
  insertEnd(head2, 8);
  insertEnd(head2, 9);
  print(head2);

  Node* newHead = mergeLL(head, head2);
  print(newHead);
  return 0;
}
