#include <cstddef>
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

void insertAtPos(Node*& tail, int val) {}

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
  return 0;
}
