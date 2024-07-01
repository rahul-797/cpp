#include <cstddef>
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* arb;

  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->arb = NULL;
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
    cout << temp->data << " (";
    if (temp->arb != NULL) cout << temp->arb->data;
    cout << ") -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void cloneLL(Node*& head) {
  Node* temp = head;
  Node* clone = new Node(head->data);
  Node* temp2 = clone;
  Node* prev = clone;
  while (temp != NULL) {
    if (temp == head) {
      clone->arb = temp->arb;
      temp = temp->next;
      continue;
    }
    Node* ptr = new Node(temp->data);
    prev->next = ptr;
    ptr->arb = temp->arb;
    prev = ptr;
    temp = temp->next;
  }
  print(clone);
}

int main() {
  Node* head = new Node(1);
  Node* two = insertEnd(head, 2);
  Node* three = insertEnd(head, 3);
  Node* four = insertEnd(head, 4);
  Node* five = insertEnd(head, 5);
  Node* six = insertEnd(head, 6);
  Node* seven = insertEnd(head, 7);
  Node* eight = insertEnd(head, 8);
  Node* nine = insertEnd(head, 9);

  head->arb = four;
  three->arb = nine;
  six->arb = seven;
  five->arb = two;
  seven->arb = four;
  nine->arb = six;
  cout << "Values in brackets represents the node pointed to by the arbitrary "
          "pointer"
       << endl;
  cout << "Original LL:" << endl;
  print(head);
  cout << endl;
  cout << "Cloned LL:" << endl;
  cloneLL(head);
  return 0;
}
