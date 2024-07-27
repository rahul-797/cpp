#include <iostream>
#include <vector>
using namespace std;

class Node {
 public:
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* insert(Node* node, int val) {
  if (node == NULL) {
    Node* root = new Node(val);
    return root;
  }
  if (val == node->data) {
    cout << "Already exists" << endl;
    return NULL;
  }
  if (node->left == NULL && val < node->data) {
    Node* temp = new Node(val);
    node->left = temp;
    return temp;
  }
  if (node->right == NULL && val > node->data) {
    Node* temp = new Node(val);
    node->right = temp;
    return temp;
  }
  return (val < node->data) ? insert(node->left, val)
                            : insert(node->right, val);
}

void print(Node* node) {
  if (node == NULL) {
    return;
  }
  print(node->left);
  cout << node->data << " ";
  print(node->right);
}

Node* convert(int* arr, int start, int end) {
  if (start > end) return NULL;
  int mid = (start + end) / 2;
  if (start == 0 && end == 6) {
    mid = 0;
  }
  Node* root = new Node(arr[mid]);
  root->left = convert(arr, start, mid - 1);
  root->right = convert(arr, mid + 1, end);
  return root;
}

int main() {
  int arr[7] = {1, 2, 3, 4, 5, 6, 7};
  Node* root = convert(arr, 0, 6);
  print(root);
  cout << endl;
  return 0;
}
