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
  struct Node *next;
} Node;

Node *hashTable[TABLE_SIZE];

int hash_function(int key) { return key % TABLE_SIZE; }

void insert(int key) {
  int index = hash_function(key);
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = hashTable[index];
  hashTable[index] = newNode;
}

void display() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("[%d]: ", i);
    Node *temp = hashTable[i];
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

// quadratic probing for collision resolution

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

int hash_function(int key) { return key % TABLE_SIZE; }

void insert(int key) {
  int index, i = 0;
  while (i < TABLE_SIZE) {
    index = (hash_function(key) + i * i) % TABLE_SIZE;
    if (hashTable[index] == EMPTY) {
      hashTable[index] = key;
      return;
    }
    i++;
  }
  printf("Table is full, could not insert key: %d\n", key);
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
  insert(50);

  display();
  return 0;
}

// dynamic hash table resizing

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5
#define LOAD_FACTOR_THRESHOLD 0.7

typedef struct {
  int *table;
  int size;
  int count;
} HashTable;

int hash_function(int key, int size) { return key % size; }

void resize(HashTable *ht);

void insert(HashTable *ht, int key) {
  if ((float)ht->count / ht->size > LOAD_FACTOR_THRESHOLD) {
    resize(ht);
  }

  int index = hash_function(key, ht->size);
  while (ht->table[index] != -1) {
    index = (index + 1) % ht->size;
  }
  ht->table[index] = key;
  ht->count++;
}

void resize(HashTable *ht) {
  int new_size = ht->size * 2;
  int *new_table = (int *)malloc(new_size * sizeof(int));

  for (int i = 0; i < new_size; i++) new_table[i] = -1;

  for (int i = 0; i < ht->size; i++) {
    if (ht->table[i] != -1) {
      int key = ht->table[i];
      int index = key % new_size;
      while (new_table[index] != -1) {
        index = (index + 1) % new_size;
      }
      new_table[index] = key;
    }
  }

  free(ht->table);
  ht->table = new_table;
  ht->size = new_size;
}

void display(HashTable *ht) {
  for (int i = 0; i < ht->size; i++) {
    printf("[%d]: %d\n", i, ht->table[i]);
  }
}

int main() {
  HashTable ht;
  ht.size = INITIAL_SIZE;
  ht.count = 0;
  ht.table = (int *)malloc(ht.size * sizeof(int));

  for (int i = 0; i < ht.size; i++) ht.table[i] = -1;

  insert(&ht, 10);
  insert(&ht, 20);
  insert(&ht, 30);
  insert(&ht, 40);
  insert(&ht, 50);
  insert(&ht, 60);  // Causes resizing

  display(&ht);
  free(ht.table);
  return 0;
}

// perfect hashing

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

typedef struct {
  int *table;
  int size;
} SecondaryTable;

SecondaryTable primaryTable[TABLE_SIZE];

int hash_function(int key) { return key % TABLE_SIZE; }

void insert(int key) {
  int index = hash_function(key);

  if (primaryTable[index].size == 0) {
    primaryTable[index].size = 2;  // Initially allocate space for 2 elements
    primaryTable[index].table =
        (int *)malloc(primaryTable[index].size * sizeof(int));
    for (int i = 0; i < primaryTable[index].size; i++)
      primaryTable[index].table[i] = -1;
  }

  for (int i = 0; i < primaryTable[index].size; i++) {
    if (primaryTable[index].table[i] == -1) {
      primaryTable[index].table[i] = key;
      return;
    }
  }

  // Resize if needed
  int new_size = primaryTable[index].size * 2;
  int *new_table = (int *)malloc(new_size * sizeof(int));
  for (int i = 0; i < new_size; i++) new_table[i] = -1;

  for (int i = 0; i < primaryTable[index].size; i++)
    new_table[i] = primaryTable[index].table[i];

  new_table[primaryTable[index].size] = key;
  free(primaryTable[index].table);
  primaryTable[index].table = new_table;
  primaryTable[index].size = new_size;
}

void display() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("[%d]: ", i);
    if (primaryTable[i].size > 0) {
      for (int j = 0; j < primaryTable[i].size; j++) {
        if (primaryTable[i].table[j] != -1) {
          printf("%d ", primaryTable[i].table[j]);
        }
      }
    }
    printf("\n");
  }
}

int main() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    primaryTable[i].size = 0;
    primaryTable[i].table = NULL;
  }

  insert(10);
  insert(15);
  insert(20);
  insert(25);
  insert(30);
  insert(35);

  display();

  for (int i = 0; i < TABLE_SIZE; i++)
    if (primaryTable[i].table) free(primaryTable[i].table);

  return 0;
}
