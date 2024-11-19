#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for chaining
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Hash table for chaining
Node* chainingTable[TABLE_SIZE];

// Hash table for open addressing
int openAddressingTable[TABLE_SIZE];

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Collision Resolution: Chaining
void insertChaining(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if (!chainingTable[index]) {
        chainingTable[index] = newNode;
    } else {
        Node* temp = chainingTable[index];
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayChaining() {
    printf("Hash Table (Chaining):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* temp = chainingTable[i];
        while (temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Collision Resolution: Open Addressing (Linear Probing)
void insertOpenAddressing(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (openAddressingTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash Table is full, cannot insert key %d.\n", key);
            return;
        }
    }

    openAddressingTable[index] = key;
}

void displayOpenAddressing() {
    printf("\nHash Table (Open Addressing):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: %d\n", i, openAddressingTable[i]);
    }
}

// Main function
int main() {
    // Initialize hash tables
    for (int i = 0; i < TABLE_SIZE; i++) {
        chainingTable[i] = NULL;
        openAddressingTable[i] = -1;
    }

    // Insert elements
    int keys[] = {19, 27, 36, 10, 64, 89, 28};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insertChaining(keys[i]);
        insertOpenAddressing(keys[i]);
    }

    // Display tables
    displayChaining();
    displayOpenAddressing();

    return 0;
}