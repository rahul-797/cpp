#include <iostream>
#include <queue>
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

//////////////////////////////////////////////////////////
int depth(Node* node) {
  if (node == NULL) {
    return 0;
  } else {
    int lDepth = depth(node->left);
    int rDepth = depth(node->right);
    if (lDepth > rDepth) {
      return lDepth + 1;
    } else {
      return rDepth + 1;
    }
  }
}

void printCurrentLevel(Node* node, int depth) {
  if (node == NULL) {
    return;
  }
  if (depth == 1) cout << node->data << " ";
  if (depth > 1) {
    printCurrentLevel(node->left, depth - 1);
    printCurrentLevel(node->right, depth - 1);
  }
}

void bfsTraversal(Node* node, int depth) {
  for (int i = 1; i <= depth; i++) {
    printCurrentLevel(node, i);
  }
}

//////////////////////////////////////////////////////////
void bfsUsingQueue(Node* node) {
  if (node == NULL) return;
  queue<Node*> q;
  q.push(node);
  while (!q.empty()) {
    cout << q.front()->data << " ";
    if (q.front()->left != NULL) q.push(q.front()->left);
    if (q.front()->right != NULL) q.push(q.front()->right);
    q.pop();
  }
  cout << endl;
}

//////////////////////////////////////////////////////////
void printCurrLevel(Node* node, int height, bool order) {
  if (node == NULL) return;
  if (height == 1) cout << node->data << " ";
  if (height > 1) {
    if (order) {
      printCurrLevel(node->left, height - 1, order);
      printCurrLevel(node->right, height - 1, order);
    } else {
      printCurrLevel(node->right, height - 1, order);
      printCurrLevel(node->left, height - 1, order);
    }
  }
}

void spiralBFS(Node* node) {
  bool order = true;
  int height = depth(node);
  for (int i = 1; i <= height; i++, order = !order) {
    printCurrLevel(node, i, order);
  }
}
//////////////////////////////////////////////////////////

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
  cout << "Depth: " << depth(root) << endl;
  bfsTraversal(root, depth(root));
  cout << endl;
  bfsUsingQueue(root);

  spiralBFS(root);
  return 0;
}
