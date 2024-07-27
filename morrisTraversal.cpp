#include <codecvt>
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

void print(Node* node) {
  if (node == NULL) {
    return;
  }
  print(node->left);
  cout << node->data << " ";
  print(node->right);
  // on top: preorder, middle: inorder, last: postorder
}

void morrisTraversal(vector<int>& vec, Node* node) {
  Node* current = node;
  while (current != NULL) {
    if (current->left == NULL) {
      vec.push_back(current->data);
      current = current->right;
    } else {
      Node* prev = current->left;
      while (prev->right && prev->right != current) {
        prev = prev->right;
      }
      if (prev->right == NULL) {
        prev->right = current;
        current = current->left;
      } else {
        prev->right = NULL;
        vec.push_back(current->data);
        current = current->right;
      }
    }
  }
}

int main() {
  Node* root = new Node(3);
  root->left = new Node(8);
  root->left->left = new Node(4);
  root->left->right = new Node(7);
  root->left->right->left = new Node(2);
  root->left->right->right = new Node(6);
  root->right = new Node(11);
  root->right->right = new Node(9);
  root->right->right->left = new Node(13);

  vector<int> vec;
  morrisTraversal(vec, root);
  for (auto i : vec) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
