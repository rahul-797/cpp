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

void findMid(Node*& head) {
  Node* fast = head;
  Node* slow = head;
  int pos = 1;
  int value;
  while (fast->next != NULL) {
    fast = fast->next;
    if (fast->next == NULL) {
      break;
    }
    slow = slow->next;
    fast = fast->next;
    pos++;
  }
  cout << "The mid is at position: " << pos << " Value: " << slow->data << endl;
}

int main() {
  Node* head = new Node(1);
  int i = 15;
  while ((i--)) {
    insertEnd(head, 16 - i);
  }
  print(head);

  findMid(head);

  return 0;
}
