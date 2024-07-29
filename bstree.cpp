#include <iostream>
#include <queue>
#include <stack>
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
// for reverse traversal, just start from end and decrement
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
  cout << endl;
}
//////////////////////////////////////////////////////////
void spiralBFSStack(Node* node) {
  if (node == NULL) return;
  stack<Node*> s1;
  stack<Node*> s2;
  s1.push(node);

  while (!s1.empty() || !s2.empty()) {
    while (!s1.empty()) {
      Node* temp = s1.top();
      cout << temp->data << " ";
      s1.pop();
      if (temp->left) s2.push(temp->left);
      if (temp->right) s2.push(temp->right);
    }
    while (!s2.empty()) {
      Node* temp = s2.top();
      cout << temp->data << " ";
      s2.pop();
      if (temp->left) s1.push(temp->left);
      if (temp->right) s1.push(temp->right);
    }
  }
  cout << endl;
}
//////////////////////////////////////////////////////////
void reverseBFS(Node* node) {
  stack<Node*> s;
  queue<Node*> q;
  q.push(node);
  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();
    s.push(curr);
    if (curr->right) {
      q.push(curr->right);
    }
    if (curr->left) {
      q.push(curr->left);
    }
  }
  while (!s.empty()) {
    cout << s.top()->data << " ";
    s.pop();
  }
  cout << endl;
}
//////////////////////////////////////////////////////////
int main() {
  Node* root = new Node(8);
  insert(root, 1);
  insert(root, 3);
  insert(root, 6);
  insert(root, 9);
  insert(root, 4);
  insert(root, 2);
  insert(root, 7);
  print(root);
  cout << endl;
  cout << "Depth: " << depth(root) << endl;
  bfsTraversal(root, depth(root));
  cout << endl;
  bfsUsingQueue(root);
  spiralBFS(root);
  spiralBFSStack(root);

  print(root);
  cout << endl;

  reverseBFS(root);
  return 0;
}
