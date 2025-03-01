#include <stdio.h>
#include <stdlib.h>

// Definition of a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a singly linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;  // Store the next node
        current->next = prev;      // Reverse the link
        prev = current;            // Move prev to the current node
        current = nextNode;        // Move to the next node
    }
    return prev; // New head of the reversed list
}

// Function to print a singly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    // Creating a singly linked list using a loop
    for (int i = 1; i <= 5; i++) {
        struct Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original list: ");
    printList(head);

    // Reverse the singly linked list
    head = reverseList(head);

    printf("Reversed list: ");
    printList(head);

    return 0;
}
