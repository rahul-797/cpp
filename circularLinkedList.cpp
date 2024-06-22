#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node(int data) {
    this->data = data;
    this->next = this;
  }
};

void insertBegin(Node*& tail, int val) {
  Node* node = new Node(val);
  node->next = tail->next;
  tail->next = node;
}

void insertEnd(Node*& tail, int val) {
  Node* node = new Node(val);
  node->next = tail->next;
  tail->next = node;
  tail = node;
}

void insertAtPos(Node*& tail, int val, int pos) {
  Node* node = new Node(val);
  if (pos == 1) {
    insertBegin(tail, val);
    return;
  }
  Node* temp = tail->next;
  while ((pos--) - 2) {
    temp = temp->next;
  }
  node->next = temp->next;
  temp->next = node;
  if (temp == tail) {
    tail = node;
  }
}

void deleteBegin(Node*& tail) {
  Node* head = tail->next;
  tail->next = head->next;
  delete head;
}

void deleteEnd(Node*& tail) {
  Node* temp = tail->next;
  while (temp->next != tail) {
    temp = temp->next;
  }
  Node* tailCopy = tail;
  temp->next = tailCopy->next;
  delete tailCopy;
  tail = temp;
}

void deleteAtPos(Node*& tail, int pos) {
  if (pos == 1) {
    deleteBegin(tail);
    return;
  }
  Node* temp = tail->next;
  while ((pos--) - 2) {
    temp = temp->next;
  }
  if (temp->next == tail) {
    deleteEnd(tail);
    return;
  }
  Node* node = temp->next;
  temp->next = node->next;
  delete node;
}

void print(Node*& tail) {
  Node* head = tail->next;
  Node* temp = head;
  while (temp->next != head) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << temp->data << " ";
  cout << endl;
}

int main() {
  Node* tail = new Node(3);
  insertEnd(tail, 4);
  insertEnd(tail, 5);
  insertBegin(tail, 2);
  insertBegin(tail, 1);
  print(tail);

  insertAtPos(tail, 6, 6);
  insertAtPos(tail, 0, 1);
  print(tail);

  deleteBegin(tail);
  deleteEnd(tail);
  print(tail);

  deleteAtPos(tail, 1);
  deleteAtPos(tail, 4);
  print(tail);
  return 0;
}
