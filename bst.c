#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left, *right;
};

struct Node* newNode(int item) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct Node* insert(struct Node* node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->data)
    node->left = insert(node->left, key);
  else if (key > node->data)
    node->right = insert(node->right, key);
  return node;
}

struct Node* minValueNode(struct Node* node) {
  struct Node* current = node;
  while (current && current->left != NULL) current = current->left;
  return current;
}

struct Node* deleteNode(struct Node* root, int key) {
  if (root == NULL) return root;
  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct Node* temp = root->left;
      free(root);
      return temp;
    }
    struct Node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

struct Node* findPredecessor(struct Node* root, int key) {
  struct Node* pred = NULL;
  while (root != NULL) {
    if (key > root->data) {
      pred = root;
      root = root->right;
    } else if (key < root->data) {
      root = root->left;
    } else {
      if (root->left != NULL) {
        pred = root->left;
        while (pred->right) pred = pred->right;
      }
      break;
    }
  }
  return pred;
}

struct Node* findSuccessor(struct Node* root, int key) {
  struct Node* succ = NULL;
  while (root != NULL) {
    if (key < root->data) {
      succ = root;
      root = root->left;
    } else if (key > root->data) {
      root = root->right;
    } else {
      if (root->right != NULL) {
        succ = root->right;
        while (succ->left) succ = succ->left;
      }
      break;
    }
  }
  return succ;
}

void inorder(struct Node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int main() {
  struct Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal of the BST: ");
  inorder(root);
  printf("\n");

  root = deleteNode(root, 20);
  printf("Inorder traversal after deleting 20: ");
  inorder(root);
  printf("\n");

  struct Node* pred = findPredecessor(root, 60);
  if (pred != NULL)
    printf("Predecessor of 60: %d\n", pred->data);
  else
    printf("No predecessor found for 60\n");

  struct Node* succ = findSuccessor(root, 60);
  if (succ != NULL)
    printf("Successor of 60: %d\n", succ->data);
  else
    printf("No successor found for 60\n");

  return 0;
}
