#include <algorithm>
#include <iostream>
#include <vector>
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

void removeDuplicates(Node*& head) {
  vector<int> vec;
  vec.push_back(head->data);
  Node* prev = head;
  Node* temp = prev->next;
  while (temp != NULL) {
    if (!count(vec.begin(), vec.end(), temp->data)) {
      vec.push_back(temp->data);
      prev->next = temp;
      prev = temp;
      temp = temp->next;
      continue;
    } else {
      temp = temp->next;
    }
  }
  prev->next = NULL;
}

int main() {
  Node* head = new Node(1);
  insertEnd(head, 2);
  insertEnd(head, 1);
  insertEnd(head, 5);
  insertEnd(head, 7);
  insertEnd(head, 7);
  insertEnd(head, 1);
  insertEnd(head, 3);
  insertEnd(head, 2);
  insertEnd(head, 5);
  insertEnd(head, 3);
  insertEnd(head, 2);
  insertEnd(head, 9);
  print(head);
  removeDuplicates(head);
  cout << "After removing duplicates: ";
  print(head);
  return 0;
}
