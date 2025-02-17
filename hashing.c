// division method
#include <stdio.h>

#define TABLE_SIZE 10

int hash_division(int key) { return key % TABLE_SIZE; }

int main() {
  int keys[] = {15, 25, 35, 20, 50, 65};
  int n = sizeof(keys) / sizeof(keys[0]);

  for (int i = 0; i < n; i++) {
    printf("Key: %d -> Hash: %d\n", keys[i], hash_division(keys[i]));
  }

  return 0;
}
// hash table with chaining

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
  int key;
  struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hash_function(int key) { return key % TABLE_SIZE; }

void insert(int key) {
  int index = hash_function(key);
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = hashTable[index];
  hashTable[index] = newNode;
}

void display() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("[%d]: ", i);
    Node* temp = hashTable[i];
    while (temp) {
      printf("%d -> ", temp->key);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(25);
  insert(35);

  display();
  return 0;
}

// hash table with linear probing

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

int hash_function(int key) { return key % TABLE_SIZE; }

void insert(int key) {
  int index = hash_function(key);
  while (hashTable[index] != EMPTY) {
    index = (index + 1) % TABLE_SIZE;  // Linear Probing
  }
  hashTable[index] = key;
}

void display() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("[%d]: %d\n", i, hashTable[i]);
  }
}

int main() {
  for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = EMPTY;

  insert(10);
  insert(20);
  insert(30);
  insert(40);

  display();
  return 0;
}

// double hashing

#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

int primary_hash(int key) { return key % TABLE_SIZE; }

int secondary_hash(int key) { return 7 - (key % 7); }

void insert(int key) {
  int index = primary_hash(key);
  int step = secondary_hash(key);

  while (hashTable[index] != EMPTY) {
    index = (index + step) % TABLE_SIZE;
  }
  hashTable[index] = key;
}

void display() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("[%d]: %d\n", i, hashTable[i]);
  }
}

int main() {
  for (int i = 0; i < TABLE_SIZE; i++) hashTable[i] = EMPTY;

  insert(10);
  insert(20);
  insert(30);
  insert(40);

  display();
  return 0;
}

// universal hashing

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10
#define P 31  // A prime number larger than max key

int a, b;

void init_hash_function() {
  srand(time(NULL));
  a = rand() % (P - 1) + 1;
  b = rand() % P;
}

int universal_hash(int key) { return ((a * key + b) % P) % TABLE_SIZE; }

int main() {
  init_hash_function();
  int keys[] = {15, 25, 35, 20, 50, 65};
  int n = sizeof(keys) / sizeof(keys[0]);

  for (int i = 0; i < n; i++) {
    printf("Key: %d -> Hash: %d\n", keys[i], universal_hash(keys[i]));
  }

  return 0;
}
