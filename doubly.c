#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* temp = createNode(value);
    if (head != NULL) {
        temp->next = head;
        head->prev = temp;
    }
    return temp;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* temp = createNode(value);
    if (head == NULL) {
        return temp;
    }
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;
    temp->prev = tail;
    return head;
}

struct Node* insertAtPos(struct Node* head, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (pos == 1) {
        return insertAtBeginning(head, value);
    }
    struct Node* temp = createNode(value);
    struct Node* current = head;
    int count = 1;
    while (count < pos - 1 && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    temp->next = current->next;
    temp->prev = current;
    if (current->next != NULL)
        current->next->prev = temp;
    current->next = temp;
    return head;
}

struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->prev->next = NULL;
    free(tail);
    return head;
}

struct Node* deleteAtPos(struct Node* head, int pos) {
    if (head == NULL || pos < 1) {
        printf("Invalid position!\n");
        return head;
    }
    if (pos == 1) {
        return deleteAtBeginning(head);
    }
    struct Node* current = head;
    int count = 1;
    while (count < pos && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Position out of bounds!\n");
        return head;
    }
    if (current->next != NULL)
        current->next->prev = current->prev;
    if (current->prev != NULL)
        current->prev->next = current->next;
    free(current);
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* createList(int arr[], int size) {
    struct Node* head = NULL;
    for (int i = 0; i < size; i++) {
        head = insertAtEnd(head, arr[i]);
    }
    return head;
}

int main() {
    int arr[5] = {11, 21, 31, 41, 51};
    struct Node* head = createList(arr, 5);
    printf("The doubly linked list is: ");
    printList(head);

    head = insertAtBeginning(head, 5);
    printf("insert at beginning: ");
    printList(head);

    head = insertAtEnd(head, 99);
    printf("Insertion at end: ");
    printList(head);
    
    int pos = 3;
    head = insertAtPos(head, 42, pos);
    printf("Insert at position %d: ", pos);
    printList(head);

    head = deleteAtBeginning(head);
    printf("Delete at beginning: ");
    printList(head);

    head = deleteAtEnd(head);
    printf("Deletion at end: ");
    printList(head);
    
    pos = 2;
    head = deleteAtPos(head, pos);
    printf("Deletion at position %d: ", pos);
    printList(head);
    
    return 0;
}
