#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct node {
    int data;
    struct node *next;
};

// Global pointers for the front and rear of the queue
struct node *f = NULL;
struct node *r = NULL;

void enqueue();
void dequeue();
void print();

int main() {
    int choice;

    printf("Queue Operations:\n");
    printf("1. Insert (Enqueue)\n");
    printf("2. Delete (Dequeue)\n");
    printf("3. Print\n");
    printf("4. Exit\n");

    do {
        printf("Enter your choice:\n ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                print();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid input, try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to enqueue an element
void enqueue() {
    int value;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Queue overflow\n");
        return;
    }

    printf("Enter the data: \n");
    scanf("%d", &value);

    p->data = value;
    p->next = NULL;

    if (f == NULL) {
        // If the queue is empty
        f = p;
        r = p;
    } else {
        // Add the new node at the rear
        r->next = p;
        r = p;
    }
}

// Function to dequeue an element
void dequeue() {
    if (f == NULL) {
        printf("Queue underflow\n");
        return;
    }

    struct node *p = f;
    f = f->next;

    if (f == NULL) {
        // If the queue becomes empty, reset rear
        r = NULL;
    }

    free(p);
    printf("Element dequeued\n");
}

// Function to print the queue
void print() {
    if (f == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *t = f;
    printf("Queue list: ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

