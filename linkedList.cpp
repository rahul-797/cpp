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

void print(Node*& head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  Node* head = new Node(5);
  insertBegin(head, 4);
  insertBegin(head, 3);
  insertEnd(head, 6);
  insertEnd(head, 7);

  print(head);

  return 0;
}
