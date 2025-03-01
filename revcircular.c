#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode;
    return newNode;
}

void reverseList(struct Node* head) {
    if (head == NULL || head->next == head) {
        return;
    }
    struct Node *prev = NULL, *current = head, *nextNode = NULL;
    struct Node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);
    head->next = prev;
    tail->next = prev; // Updating circular link
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 1; i <= 3; i++) {
        struct Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        tail->next = head; // Making it circular
    }

    printf("Original list: ");
    printList(head);

    reverseList(head);

    printf("Reversed list: ");
    printList(head);
    
    return 0;
}
