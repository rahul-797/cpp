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
void reverseLLRecursion(Node*& head, Node* prev, Node* temp, Node* next,
                        bool firstCall = false) {
  if (next == NULL) {
    temp->next = prev;
    head = temp;
    return;
  }
  if (firstCall) prev->next = NULL;
  temp->next = prev;
  prev = temp;
  temp = next;
  next = next->next;
  reverseLLRecursion(head, prev, temp, next);
}

Node* kReverse(Node*& start, int k, Node* head, bool fromStart = false) {
  Node* ptr = start;
  int j = k;
  while ((j--)) {
    ptr = ptr->next;
  }
  Node* prev = start;
  if (prev->next == NULL) return head;

  Node* startBack = head;
  if (!fromStart) {
    while (startBack->next != start) {
      startBack = startBack->next;
    }
  }

  Node* temp = prev->next;
  // case of two elements
  if (temp->next == NULL) {
    temp->next = prev;
    prev->next = NULL;
    startBack->next = temp;
    start = temp;
    if (fromStart) return start;
    return head;
  }
  Node* next = temp->next;
  for (int i = k - 1; i > 0; i--) {
    if (i == k - 1 && !fromStart) startBack->next = prev;
    temp->next = prev;
    prev = temp;
    temp = next;
    if (next->next == NULL) {
      continue;
    }
    next = next->next;
  }
  start->next = ptr;
  start = prev;
  if (!fromStart) startBack->next = start;
  if (fromStart) return start;
  return head;
}

void groupReverse(Node*& head, int k) {
  int len = 0;
  Node* temp = head;
  while (temp != NULL) {
    temp = temp->next;
    len++;
  }
  temp = head;
  int count = 1;
  Node* start = head;

  for (int i = len; i >= k; i -= k, count++) {
    if (count == 1) {
      head = kReverse(head, k, head, true);
      start = head;
    } else {
      head = kReverse(start, k, head, false);
    }
    int j = k;
    while ((j--)) {
      start = start->next;
    }
  }
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

  reverseLLRecursion(head, head, head->next, head->next->next, true);
  print(head);

  groupReverse(head, 3);
  cout << endl;
  print(head);
  return 0;
}
