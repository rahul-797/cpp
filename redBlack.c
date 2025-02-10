#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
  int key;
  Color color;
  struct Node *left, *right, *parent;
} Node;

typedef struct {
  Node* root;
  Node* nil;  // Sentinel node
} RedBlackTree;

// Helper function to create a new node
Node* createNode(int key, Color color, Node* nil) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->color = color;
  newNode->left = newNode->right = newNode->parent = nil;
  return newNode;
}

// Initialize an empty Red-Black Tree
RedBlackTree* initializeTree() {
  RedBlackTree* T = (RedBlackTree*)malloc(sizeof(RedBlackTree));
  T->nil = createNode(0, BLACK, NULL);
  T->root = T->nil;
  return T;
}

// Left Rotate
void leftRotate(RedBlackTree* T, Node* x) {
  Node* y = x->right;
  x->right = y->left;
  if (y->left != T->nil) y->left->parent = x;
  y->parent = x->parent;
  if (x->parent == T->nil)
    T->root = y;
  else if (x == x->parent->left)
    x->parent->left = y;
  else
    x->parent->right = y;
  y->left = x;
  x->parent = y;
}

// Right Rotate
void rightRotate(RedBlackTree* T, Node* y) {
  Node* x = y->left;
  y->left = x->right;
  if (x->right != T->nil) x->right->parent = y;
  x->parent = y->parent;
  if (y->parent == T->nil)
    T->root = x;
  else if (y == y->parent->left)
    y->parent->left = x;
  else
    y->parent->right = x;
  x->right = y;
  y->parent = x;
}

// RB-INSERT
void rbInsert(RedBlackTree* T, int key) {
  Node* z = createNode(key, RED, T->nil);
  Node* y = T->nil;
  Node* x = T->root;
  while (x != T->nil) {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }
  z->parent = y;
  if (y == T->nil)
    T->root = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
  rbInsertFixup(T, z);
}

// RB-INSERT-FIXUP
void rbInsertFixup(RedBlackTree* T, Node* z) {
  while (z->parent->color == RED) {
    if (z->parent == z->parent->parent->left) {
      Node* y = z->parent->parent->right;
      if (y->color == RED) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->right) {
          z = z->parent;
          leftRotate(T, z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        rightRotate(T, z->parent->parent);
      }
    } else {
      Node* y = z->parent->parent->left;
      if (y->color == RED) {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      } else {
        if (z == z->parent->left) {
          z = z->parent;
          rightRotate(T, z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        leftRotate(T, z->parent->parent);
      }
    }
  }
  T->root->color = BLACK;
}

// RB-TRANSPLANT
void rbTransplant(RedBlackTree* T, Node* u, Node* v) {
  if (u->parent == T->nil)
    T->root = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else
    u->parent->right = v;
  v->parent = u->parent;
}

// TREE-MINIMUM
Node* treeMinimum(RedBlackTree* T, Node* x) {
  while (x->left != T->nil) x = x->left;
  return x;
}

// RB-DELETE
void rbDelete(RedBlackTree* T, Node* z) {
  Node* y = z;
  Node* x;
  Color y_original_color = y->color;
  if (z->left == T->nil) {
    x = z->right;
    rbTransplant(T, z, z->right);
  } else if (z->right == T->nil) {
    x = z->left;
    rbTransplant(T, z, z->left);
  } else {
    y = treeMinimum(T, z->right);
    y_original_color = y->color;
    x = y->right;
    if (y->parent == z)
      x->parent = y;
    else {
      rbTransplant(T, y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    rbTransplant(T, z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }
  if (y_original_color == BLACK) rbDeleteFixup(T, x);
  free(z);
}

// RB-DELETE-FIXUP
void rbDeleteFixup(RedBlackTree* T, Node* x) {
  while (x != T->root && x->color == BLACK) {
    if (x == x->parent->left) {
      Node* w = x->parent->right;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        leftRotate(T, x->parent);
        w = x->parent->right;
      }
      if (w->left->color == BLACK && w->right->color == BLACK) {
        w->color = RED;
        x = x->parent;
      } else {
        if (w->right->color == BLACK) {
          w->left->color = BLACK;
          w->color = RED;
          rightRotate(T, w);
          w = x->parent->right;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->right->color = BLACK;
        leftRotate(T, x->parent);
        x = T->root;
      }
    } else {
      Node* w = x->parent->left;
      if (w->color == RED) {
        w->color = BLACK;
        x->parent->color = RED;
        rightRotate(T, x->parent);
        w = x->parent->left;
      }
      if (w->right->color == BLACK && w->left->color == BLACK) {
        w->color = RED;
        x = x->parent;
      } else {
        if (w->left->color == BLACK) {
          w->right->color = BLACK;
          w->color = RED;
          leftRotate(T, w);
          w = x->parent->left;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->left->color = BLACK;
        rightRotate(T, x->parent);
        x = T->root;
      }
    }
  }
  x->color = BLACK;
}

// Inorder traversal for testing
void inorderTraversal(RedBlackTree* T, Node* x) {
  if (x != T->nil) {
    inorderTraversal(T, x->left);
    printf("%d (%s) ", x->key, x->color == RED ? "RED" : "BLACK");
    inorderTraversal(T, x->right);
  }
}

int main() {
  RedBlackTree* T = initializeTree();

  // Insert some values
  int values[] = {41, 38, 31, 12, 19, 8};
  for (int i = 0; i < 6; i++) {
    rbInsert(T, values[i]);
  }

  printf("Inorder traversal after insertion: ");
  inorderTraversal(T, T->root);
  printf("\n");

  // Delete a node
  Node* nodeToDelete = T->root->left->left;  // Node with key 12
  rbDelete(T, nodeToDelete);

  printf("Inorder traversal after deletion: ");
  inorderTraversal(T, T->root);
  printf("\n");

  return 0;
}
