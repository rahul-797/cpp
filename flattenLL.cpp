#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;
  Node* child;

  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->child = NULL;
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

Node* insertChild(Node*& head, int val) {
  Node* node = new Node(val);
  Node* temp = head;
  while (temp->child != NULL) {
    temp = temp->child;
  }
  temp->child = node;
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

void printChild(Node*& head) {
  Node* temp = head;
  cout << "Child of " << head->data << " : ";
  while (temp != NULL) {
    temp = temp->child;
    if (temp == NULL) break;
    cout << temp->data << " ";
  }
  cout << endl;
}

Node* flattenLinkedList(Node* head) {
  Node* node = head;
  Node* nextNode = node->next;
  Node* last = head;
  while (nextNode != NULL) {
    while (last->child != NULL) {
      last = last->child;
    }
    last->child = nextNode;
    last = nextNode;
    node = nextNode;
    nextNode = nextNode->next;
  }
  last->child = NULL;
  return head;
}

int main() {
  Node* head = new Node(1);
  insertChild(head, 2);
  insertChild(head, 3);
  Node* two = insertEnd(head, 4);
  insertChild(two, 5);
  insertChild(two, 6);
  Node* three = insertEnd(head, 7);
  insertChild(three, 8);
  Node* four = insertEnd(head, 9);
  printChild(head);
  printChild(two);
  printChild(three);
  printChild(four);

  cout << endl << "Flattened LL: " << endl;
  flattenLinkedList(head);
  printChild(head);
  return 0;
}
