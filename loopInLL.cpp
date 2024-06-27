#include <cstddef>
#include <iostream>
#include <unordered_map>
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

bool detectLoop(Node*& head) {
  Node* slow = head;
  Node* fast = head;
  bool isLoop = false;
  while (1) {
    slow = slow->next;
    if (fast->next == NULL) break;
    fast = fast->next;
    if (fast->next == NULL) break;
    fast = fast->next;

    if (slow == fast) {
      isLoop = true;
      break;
    }
  }
  return isLoop;
}

void breakLoop(Node*& head) {
  if (!detectLoop(head)) {
    cout << "There is no loop" << endl;
    return;
  }
  Node* temp = head;
  unordered_map<Node*, int> m;
  while (1) {
    if (!m.count(temp->next)) {
      m.insert({temp->next, temp->next->data});
      temp = temp->next;
      continue;
    }
    temp->next = NULL;
    break;
  }
}

int main() {
  Node* head = new Node(1);
  insertEnd(head, 2);
  insertEnd(head, 3);
  insertEnd(head, 4);
  insertEnd(head, 5);
  insertEnd(head, 6);
  Node* ptr = insertEnd(head, 7);
  insertEnd(head, 8);
  Node* ptr2 = insertEnd(head, 9);
  ptr2->next = ptr;

  bool isLoop = detectLoop(head);
  cout << "loop exists: " << isLoop << endl;
  breakLoop(head);
  cout << "LL after removing loop: ";
  print(head);
  return 0;
}
