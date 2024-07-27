#include <iostream>
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

void insert(Node* node, int val) {
  if (val == node->data) {
    cout << "Already exists" << endl;
    return;
  }
  if (node->left == NULL && val < node->data) {
    Node* temp = new Node(val);
    node->left = temp;
    return;
  }
  if (node->right == NULL && val > node->data) {
    Node* temp = new Node(val);
    node->right = temp;
    return;
  }
  (val < node->data) ? insert(node->left, val) : insert(node->right, val);
}

void deleteNode(Node* node, int val) {
  // it works for leaf node
  // for node with 2 children, replace it with its inorder predecessor and
  // delete
  if (node->data == val) {
    delete node;
    return;
  }
  if (node->left != NULL && val == node->left->data) {
    delete node->left;
    node->left = NULL;
    return;
  }
  if (node->right != NULL && val == node->right->data) {
    delete node->right;
    node->right = NULL;
    return;
  }
  (val < node->data) ? deleteNode(node->left, val)
                     : deleteNode(node->right, val);
}

void searchBST(Node* node, int val) {
  if (node == NULL) {
    cout << "Not found" << endl;
    return;
  }
  if (node->data == val) {
    cout << "Found" << endl;
    return;
  }
  node->data < val ? searchBST(node->right, val) : searchBST(node->left, val);
}

void print(Node* node) {
  if (node == NULL) {
    return;
  }
  cout << node->data << " ";
  print(node->left);
  print(node->right);
  // on top: preorder, middle: inorder, last: postorder
}

int main() {
  Node* root = new Node(8);
  root->left = new Node(3);
  root->left->left = new Node(1);
  root->left->right = new Node(6);
  root->left->right->left = new Node(4);
  root->left->right->right = new Node(7);
  root->right = new Node(10);
  root->right->right = new Node(14);
  root->right->right->left = new Node(13);
  print(root);
  cout << endl;
  insert(root, 2);
  insert(root, 20);
  insert(root, 15);
  print(root);
  cout << endl;
  deleteNode(root, 10);
  print(root);
  cout << endl;
  return 0;
}
