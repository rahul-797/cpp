#include <cstddef>
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

void insertBegin(Node*& head, int val) {
  Node* temp = new Node(val);
  temp->next = head;
  head = temp;
}

void insertEnd(Node*& head, int val) {
  Node* node = new Node(val);
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
}

void insertAtPos(Node*& head, int val, int pos) {
  Node* node = new Node(val);
  Node* temp = head;
  if (pos == 1) {
    node->next = head;
    head = node;
    return;
  }
  while ((pos--) - 2) {
    temp = temp->next;
  }
  node->next = temp->next;
  temp->next = node;
}

void deleteBegin(Node*& head) {
  Node* temp = head->next;
  delete head;
  head = temp;
}

void deleteEnd(Node*& head) {
  Node* temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  delete temp->next;
  temp->next = NULL;
}

void deleteAtPos(Node*& head, int pos) {
  Node* temp = head;
  if (pos == 1) {
    head = head->next;
    delete temp;
    return;
  }
  while ((pos--) - 2) {
    temp = temp->next;
  }
  Node* temp2 = temp->next->next;
  delete temp->next;
  temp->next = temp2;
}

void print(Node*& head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

void reverseLL(Node*& head) {
  Node* prev = head;
  Node* temp = head->next;
  Node* next = temp->next;
  prev->next = NULL;
  while (next != NULL) {
    temp->next = prev;
    prev = temp;
    temp = next;
    next = next->next;
  }
  temp->next = prev;
  head = temp;
}

int main() {
  Node* head = new Node(5);
  insertBegin(head, 4);
  insertBegin(head, 3);
  insertEnd(head, 7);
  insertEnd(head, 8);
  print(head);

  insertAtPos(head, 6, 4);
  insertAtPos(head, 1, 1);
  insertAtPos(head, 2, 2);
  insertAtPos(head, 9, 9);
  print(head);

  deleteBegin(head);
  deleteEnd(head);
  print(head);

  deleteAtPos(head, 1);
  print(head);

  reverseLL(head);
  print(head);

  return 0;
}
