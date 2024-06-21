#include <cstddef>
#include <iostream>
using namespace std;

class Node {
 public:
  Node* prev;
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }
};

void insertBegin(Node*& head, int val) {
  Node* temp = new Node(val);
  temp->next = head;
  head->prev = temp;
  head = temp;
}

void insertEnd(Node*& head, int val) {
  Node* node = new Node(val);
  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
  node->prev = temp;
}

void insertAtPos(Node*& head, int val, int pos) {
  Node* node = new Node(val);
  if (pos == 1) {
    insertBegin(head, val);
    return;
  }
  Node* temp = head;
  while ((pos--) - 2) {
    temp = temp->next;
  }
  if (temp->next == NULL) {
    insertEnd(head, val);
    return;
  }
  node->next = temp->next;
  node->next->prev = node;
  temp->next = node;
  node->prev = temp;
}

void deleteBegin(Node*& head) {
  Node* temp = head;
  head->next->prev = NULL;
  head = head->next;
  delete temp;
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
  if (pos == 1) {
    deleteBegin(head);
    return;
  }
  Node* temp = head;
  Node* temp2 = head;
  while ((pos--) - 2) {
    temp = temp->next;
  }
  if (temp->next->next == NULL) {
    deleteEnd(head);
    return;
  }
  temp2 = temp->next;
  temp->next = temp->next->next;
  temp2->next->prev = temp;
  delete temp2;
}

void print(Node*& head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  Node* head = new Node(3);
  insertBegin(head, 2);
  insertBegin(head, 1);
  insertEnd(head, 4);
  insertEnd(head, 5);
  print(head);

  insertAtPos(head, 6, 6);
  insertAtPos(head, 0, 1);
  print(head);

  deleteBegin(head);
  deleteEnd(head);
  print(head);

  deleteAtPos(head, 5);
  deleteAtPos(head, 1);
  print(head);
  return 0;
}
